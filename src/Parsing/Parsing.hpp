/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Parsing
*/

#include "IParsing.hpp"

#ifndef PARSING_HPP_
    #define PARSING_HPP_

    class Parsing : public IParsing {
        public:
            Parsing() = default;
            ~Parsing() = default;

            void help() override;
            void parseFile(const std::string &file) override;
            void checkArgs(int ac, char **av) override;
            void loadData() override;
            void dumpData() override;
            libconfig::Setting &lookUp(const std::string &path) override;
            void lookUpValue(const std::string &path, int &value) override;
            void lookUpValue(const std::string &path, std::string &value) override;
            void lookUpValue(const std::string &path, float &value) override;
            camera getCamera() const { return _camera; }
            light getLight() const { return _light; }
            Hitable_list *getWorld() const { return _world; }
    };

#endif /* !PARSING_HPP_ */
