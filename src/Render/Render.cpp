/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Render
*/

#include "Render.hpp"

std::atomic<bool> stopFlag(false);

void signalHandler(int signum) {
    (void)signum;
    stopFlag = true;
}

Vec3 Render::RayColor(const Ray &r, Hitable *world, int depth)
{
    hit_record rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec)) {
        Ray scattered;
        Vec3 attenuation;
        Vec3 emitted = rec.mat_ptr->emitted(rec.u, rec.v, rec.p);
        if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
            return emitted + attenuation * RayColor(scattered, world, depth + 1);
        } else {
            return emitted;
        }
    } else {
        return Background;
    }
}

void resetRender(Observer &observer) {
    Parsing parsing;
    printf("File modified, reloading...\n");
    parsing.parseFile(observer.getFilename());
    printf("File reloaded\n");
    parsing.loadData();
    parsing.dumpData();

    std::string inputFilename(observer.getFilename());
    inputFilename = inputFilename.substr(inputFilename.find_last_of("/") + 1);
    std::string filename = inputFilename.substr(0, inputFilename.find_last_of(".")) + ".ppm";

    Render render;
    render.RenderImage(parsing, filename);
    exit(0);
}

void Render::RenderImage(Parsing &parsing, std::string filename) {
	signal(SIGINT, signalHandler);
    Hitable *world = parsing.getWorld();

    Observer observer;
    observer.setFilename(filename);
    observer.firstObserver();

    int image_width = parsing.getCamera().resolution.width;
    int image_height = parsing.getCamera().resolution.height;
    int ns = parsing.getCamera().quality;
  
    Camera camera(parsing);

    Color RGB(parsing.getLight().skycolor.r, parsing.getLight().skycolor.g, parsing.getLight().skycolor.b);

    Background = RGB.RGBtoVec3();

    CreatePPM createPPM;

    createPPM.setResolution(image_width, image_height);
    createPPM.setFilename(filename);

    std::mutex mtx;
    std::vector<std::thread> threads;
    int num_threads = std::thread::hardware_concurrency();

    // Graphics graphics;

    // graphics.createWindow(image_width, image_height);
    for (int t = 0; t < num_threads; t++) {
        threads.push_back(std::thread([&, t]() {
            for (int i = image_height - 1 - t; i >= 0; i -= num_threads) {
                for (int j = 0; j < image_width; j++) {
                    if (stopFlag) {
                        exit(0);
                    }

                    Vec3 col(0, 0, 0);
                    for (int s = 0; s < ns; s++) {
                        float u = float(j + drand48()) / float(image_width);
                        float v = float(i + drand48()) / float(image_height);
                        Ray r = camera.getRay(u, v);
                        col += RayColor(r, world, 0);
                    }
                    col /= float(ns);
                    col = Vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

                    mtx.lock();
                    createPPM.setPixel(j, i, int(255.99 * col[0]), int(255.99 * col[1]), int(255.99 * col[2]));
                    // graphics.setPixelColor(j, i, sf::Color(int(255.99 * col[0]), int(255.99 * col[1]), int(255.99 * col[2])));
                    mtx.unlock();
                }
            }
            // graphics.display_window();
        }));
    }

    // graphics.loop();

    for (auto& thread : threads) {
        thread.join();
    }

    if (observer.isModified())
        resetRender(observer);

    createPPM.createPPM();
}
