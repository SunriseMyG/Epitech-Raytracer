/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** ErrorsParsing
*/

#include "Errors.hpp"

#ifndef ERRORSPARSING_HPP_
    #define ERRORSPARSING_HPP_

    class ErrorsParsing : public Errors {
        public:
            explicit ErrorsParsing(const std::string &message)
                : Errors(message) {}
    };

#endif /* !ERRORSPARSING_HPP_ */

