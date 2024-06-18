/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** Sfml
*/

#include "Graphics.hpp"

void Graphics::createWindow(int width, int height)
{
    window.create(sf::VideoMode(width, height), "Raytracer", sf::Style::Close);
}

void Graphics::destroyWindow()
{
    window.close();
}

void Graphics::setPixelColor(int x, int y, sf::Color color)
{
    sf::RectangleShape pixel(sf::Vector2f(1, 1));
    pixel.setPosition(x, y);
    pixel.setFillColor(color);
    window.draw(pixel);
}

void Graphics::loop()
{
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}

void Graphics::display_window()
{
    window.display();
}
