/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Observer
*/

#include "Observer.hpp"

void Observer::setFilename(std::string filename)
{
    _filename = filename;
    _filename = _filename.substr(0, _filename.find_last_of("."));
    _filename = _filename + ".cfg";
    _filename = "./scenes/" + _filename;
}

void Observer::firstObserver()
{
    struct stat result;
    stat(_filename.c_str(), &result);
    _last_modified = result.st_mtime;
}

bool Observer::isModified()
{
    struct stat result;
    stat(_filename.c_str(), &result);
    if (result.st_mtime != _last_modified) {
        _last_modified = result.st_mtime;
        return true;
    }
    return false;
}
