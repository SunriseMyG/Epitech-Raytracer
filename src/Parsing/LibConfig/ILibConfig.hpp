/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** ILibConfig
*/

#ifndef ILIBCONFIG_HPP_
    #define ILIBCONFIG_HPP_

    #include <libconfig.h++>
    #include <iostream>

    class ILibConfig {
        protected:
            std::string _file;
            libconfig::Config cfg;

        public:
            ILibConfig() = default;
            ~ILibConfig() = default;
            virtual void setFile(const std::string &file) = 0;
            virtual void openFile() = 0;
            virtual libconfig::Setting &lookUp(const std::string &path) = 0;

            template <typename T>
            void lookUpValue(const std::string &path, T &value) {
                try {
                    cfg.lookupValue(path, value);
                } catch (const libconfig::SettingNotFoundException &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }

            virtual void lookUpValue(const std::string &path, std::string &value) {
                ILibConfig::lookUpValue<std::string>(path, value);
            }

            virtual void lookUpValue(const std::string &path, bool &value) {
                ILibConfig::lookUpValue<bool>(path, value);
            }

            virtual void lookUpValue(const std::string &path, int &value) {
                ILibConfig::lookUpValue<int>(path, value);
            }

            virtual void lookUpValue(const std::string &path, float &value) {
                ILibConfig::lookUpValue<float>(path, value);
            }
    };

#endif /* !ILIBCONFIG_HPP_ */
