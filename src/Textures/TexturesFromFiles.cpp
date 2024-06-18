/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** TexturesFromFiles
*/

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "TexturesFromFiles.hpp"

TexturesFromFiles::TexturesFromFiles(const char *filename)
{
    _filename = filename;
    if (!load(_filename)) {
        std::cerr << "Error: could not load texture image file " << _filename << std::endl;
    }
}

bool TexturesFromFiles::load(const std::string &filename)
{
    auto n = bytes_per_pixel;
    fdata = stbi_loadf(filename.c_str(), &width, &height, &n, 0);

    if (fdata == nullptr) {
        std::cerr << "Error: could not load texture image file " << filename << std::endl;
        return false;
    }

    bytes_per_scanline = bytes_per_pixel * width;
    convert_to_bytes();
    return true;
}

const unsigned char *TexturesFromFiles::pixel_data(int x, int y) const
{
    static unsigned char magenta[] = {255, 0, 255};

    if (fdata == nullptr) {
        return magenta;
    }
    x = clamp(x, 0, width);
    y = clamp(y, 0, height);

    return bdata + y * bytes_per_scanline + x * bytes_per_pixel;
}

int TexturesFromFiles::clamp(int x, int low, int high)
{
    if (x < low) return low;
    if (x < high) return x;
    return high - 1;
}

unsigned char TexturesFromFiles::float_to_byte(float value)
{
    if (value <= 0.0)
        return 0;
    if (1.0 <= value)
        return 255;
    return static_cast<unsigned char>(256.0 * value);
}

void TexturesFromFiles::convert_to_bytes()
{
    int total_bytes = width * height * bytes_per_pixel;
    bdata = new unsigned char[total_bytes];

    auto *bptr = bdata;
    auto *fptr = fdata;
    for (int i = 0; i < total_bytes; i++, fptr++, bptr++) {
        *bptr = float_to_byte(*fptr);
    }
}

int TexturesFromFiles::widths() const
{
    return (fdata == nullptr) ? 0 : width;
}

int TexturesFromFiles::heights() const
{
    return (fdata == nullptr) ? 0 : height;
}
