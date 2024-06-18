/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** TexturesFromFiles
*/

#include <iostream>

#ifndef TEXTURESFROMFILES_HPP_
    #define TEXTURESFROMFILES_HPP_

    class TexturesFromFiles {
        public:
            TexturesFromFiles() {};
            ~TexturesFromFiles() = default;

            TexturesFromFiles(const char *filename);
            bool load(const std::string &filename);
            const unsigned char *pixel_data(int x, int y) const;
            int widths() const;
            int heights() const;
        protected:
        private:
            std::string _filename;
            int width = 0;
            int height = 0;
            const int bytes_per_pixel = 3;
            float *fdata = nullptr;
            unsigned char *bdata = nullptr;
            int bytes_per_scanline = 0;
            static int clamp(int x, int low, int high);
            static unsigned char float_to_byte(float value);
            void convert_to_bytes();
    };

#endif /* !TEXTURESFROMFILES_HPP_ */
