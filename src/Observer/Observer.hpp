/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Observer
*/

#include <iostream>
#include <vector>
#include <string>
#include <sys/stat.h>

#ifndef OBSERVER_HPP_
    #define OBSERVER_HPP_

    class Observer {
        public:
            Observer() = default;
            ~Observer() = default;
            void setFilename(std::string filename);
            void firstObserver();
            bool isModified();
            char *getFilename() { return (char *)_filename.c_str(); };

        protected:
            std::string _filename;
            time_t _last_modified;
    };

#endif /* !OBSERVER_HPP_ */
