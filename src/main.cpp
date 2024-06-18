/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** main
*/

#include "Parsing/Parsing.hpp"
#include "Render/Render.hpp"


int main(int ac, char **av)
{
    Parsing parsing;
    parsing.checkArgs(ac, av);
    parsing.parseFile(av[1]);
    parsing.loadData();
    parsing.dumpData();

    std::string inputFilename(av[1]);
    inputFilename = inputFilename.substr(inputFilename.find_last_of("/") + 1);
    std::string filename = inputFilename.substr(0, inputFilename.find_last_of(".")) + ".ppm";

    Render render;
    render.RenderImage(parsing, filename);
    return 0;
}
