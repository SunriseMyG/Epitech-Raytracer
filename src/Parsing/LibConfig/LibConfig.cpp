/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** LibConfig
*/

#include "LibConfig.hpp"

void LibConfig::setFile(const std::string &file)
{
    _file = file;
}

void LibConfig::openFile()
{
    if (_file.empty()) {
        std::cerr << "No file to open" << std::endl;
        exit(84);
    }
    try {
        cfg.readFile(_file.c_str());
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        exit(84);
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        exit(84);
    }
}

libconfig::Setting &LibConfig::lookUp(const std::string &path)
{
    try {
        libconfig::Setting &setting = cfg.lookup(path);
        return setting;
    } catch (const libconfig::SettingNotFoundException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }
}

void LibConfig::lookUpValue(const std::string &path, std::string &value)
{
    cfg.lookupValue(path, value);
}
void LibConfig::lookUpValue(const std::string &path, bool &value)
{
    cfg.lookupValue(path, value);
}

void LibConfig::lookUpValue(const std::string &path, int &value)
{
    cfg.lookupValue(path, value);
}

void LibConfig::lookUpValue(const std::string &path, float &value)
{
    cfg.lookupValue(path, value);
}
