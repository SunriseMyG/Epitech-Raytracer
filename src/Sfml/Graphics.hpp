/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** Sfml
*/

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <thread>
#include <mutex>
#include <queue>

#ifndef SFML_HPP_
    #define SFML_HPP_

    class Graphics {
        public:
            Graphics() = default;
            ~Graphics() = default;

            void createWindow(int width, int height);
            void setPixelColor(int x, int y, sf::Color color);
            void destroyWindow();
            void loop();
            void display_window();
        protected:
            sf::RenderWindow window;
            sf::Event event;
            sf::VertexArray pixels;
            std::mutex mutex;
            sf::RectangleShape pixel;

        private:
    };

#endif /* !SFML_HPP_ */
