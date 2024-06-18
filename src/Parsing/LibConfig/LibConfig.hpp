/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** LibConfig
*/

#ifndef LIBCONFIG_HPP_
    #define LIBCONFIG_HPP_

    #include "ILibConfig.hpp"

    class LibConfig : public ILibConfig {
        public:
            LibConfig() = default;
            ~LibConfig() = default;

            void setFile(const std::string &file) override;
            void openFile() override;
            libconfig::Setting &lookUp(const std::string &path) override;
            void lookUpValue(const std::string &path, std::string &value) override;
            void lookUpValue(const std::string &path, bool &value) override;
            void lookUpValue(const std::string &path, int &value) override;
            void lookUpValue(const std::string &path, float &value) override;

        protected:
            std::string _file;
    };

#endif /* !LIBCONFIG_HPP_ */
