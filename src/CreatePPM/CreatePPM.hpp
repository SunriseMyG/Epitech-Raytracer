/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** CreatePPM
*/

#include "ICreatePPM.hpp"

#ifndef CREATEPPM_HPP_
    #define CREATEPPM_HPP_

    class CreatePPM : public ICreatePPM {
        public:
            CreatePPM() = default;
            ~CreatePPM() = default;

            void createPPM() override;
            void setPixel(int x, int y, int r, int g, int b) override;
            void setResolution(int x, int y) override;
            void setFilename(std::string filename) override;
        protected:
            int _x;
            int _y;
            std::string _filename;
            std::vector<std::vector<std::vector<int>>> _pixels;
        private:
    };

#endif /* !CREATEPPM_HPP_ */
