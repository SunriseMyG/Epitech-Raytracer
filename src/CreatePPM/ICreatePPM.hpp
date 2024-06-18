/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** IPpm
*/

#ifndef ICreatePPM_HPP_
    #define ICreatePPM_HPP_

    #include <iostream>
    #include <vector>
    #include <fstream>
    #include <string>
    #include <cmath>
    #include <sys/stat.h>
    #include <sys/types.h>

    class ICreatePPM {
        public:
            ICreatePPM() = default;
            ~ICreatePPM() = default;

            virtual void createPPM() = 0;
            virtual void setPixel(int x, int y, int r, int g, int b) = 0;
            virtual void setResolution(int x, int y) = 0;
            virtual void setFilename(std::string filename) = 0;

        protected:
            int _x;
            int _y;
            std::string _filename;
            std::vector<std::vector<std::vector<int>>> _pixels;
    };

#endif /* !ICreatePPM */
