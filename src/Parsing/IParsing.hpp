/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** IParsing
*/

#ifndef IPARSING_HPP_
    #define IPARSING_HPP_

    #include <iostream>
    #include <vector>
    #include "LibConfig/LibConfig.hpp"
    #include "../Errors/ErrorsParsing.hpp"
    #include "../UtilsObject/Hitable/Hitable.hpp"
    #include "../UtilsObject/Hitable/Hitable_list.hpp"
    #include "../Builder/Builder.hpp"
    #include "../UtilsObject/Color/Color.hpp"
    #include "../Factory/Factory.hpp"

    class IParsing {
        protected:
            LibConfig _libConfig;
            struct camera {
                struct resolution {
                    int width;
                    int height;
                } resolution;
                struct position {
                    int x;
                    int y;
                    int z;
                } position;
                struct rotation {
                    int x;
                    int y;
                    int z;
                } rotation;
                float fov;
                float dof;
                int quality = 100;
            } _camera;

            struct light {
                struct skycolor {
                    int r;
                    int g;
                    int b;
                };
                skycolor skycolor;
                struct position {
                    float x;
                    float y;
                    float z;
                };
                std::vector<position> positions;
            } _light;

            Hitable_list *_world;
            
        public:
            IParsing() = default;
            ~IParsing() = default;

            virtual void help() = 0;
            virtual void parseFile(const std::string &file) = 0;
            virtual void checkArgs(int ac, char **av) = 0;
            virtual void loadData() = 0;
            virtual void dumpData() = 0;
            virtual libconfig::Setting &lookUp(const std::string &path) = 0;
            virtual void lookUpValue(const std::string &path, int &value) = 0;
            virtual void lookUpValue(const std::string &path, std::string &value) = 0;
            virtual void lookUpValue(const std::string &path, float &value) = 0;
    };

#endif /* !IPARSING_HPP_ */
