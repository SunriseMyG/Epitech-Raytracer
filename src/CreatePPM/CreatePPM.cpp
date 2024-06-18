/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** CreatePPM
*/

#include "CreatePPM.hpp"

void CreatePPM::createPPM()
{
    struct stat buffer;
    if (stat("screenshots", &buffer) != 0) {
        mkdir("screenshots", 0777);
    }

    std::ofstream fout("screenshots/" + _filename);
    fout << "P6\n" << _x << " " << _y << "\n255\n";
    for (int i = 0; i < _y; i++) {
        for (int j = 0; j < _x; j++) {
            fout << (char)_pixels[i][j][0] << (char)_pixels[i][j][1] << (char)_pixels[i][j][2];
        }
    }
    fout.close();
}

void CreatePPM::setPixel(int x, int y, int r, int g, int b)
{
    if (x >= 0 && x < _x && y >= 0 && y < _y) {
        _pixels[y][x][0] = r;
        _pixels[y][x][1] = g;
        _pixels[y][x][2] = b;
    }
}

void CreatePPM::setResolution(int x, int y)
{
    _x = x;
    _y = y;
    _pixels.resize(_y, std::vector<std::vector<int>>(_x, std::vector<int>(3)));
}

void CreatePPM::setFilename(std::string filename)
{
    _filename = filename;
}
