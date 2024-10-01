#include "kalam.h"
#include "load.h"
#include "save.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#if defined(__has_include)
    #if __has_include(<filesystem>)
        #include <filesystem>
        namespace fs = std::filesystem;
    #else
        #include <boost/filesystem.hpp>
        namespace fs = boost::filesystem;
    #endif
#else
    #include <boost/filesystem.hpp>
    namespace fs = boost::filesystem;
#endif

namespace kalam {

Image::Image(int w, int h, int ch)
    : width(w), height(h), channels(ch), data(new unsigned char[w * h * ch]()) {}

Image::~Image() {
    delete[] data;
}

bool Image::isInBounds(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool Image::isValid() const {
    return data != nullptr;
}

unsigned char Image::getPixel(int x, int y, int channel) const {
    if (!isInBounds(x, y) || channel >= channels)
        return 0; 
    return data[(y * width + x) * channels + channel];
}

void Image::setPixel(int x, int y, int channel, unsigned char value) {
    if (isInBounds(x, y) && channel < channels) {
        data[(y * width + x) * channels + channel] = value;
    }
}

void Image::copyToLargerCanvas(Image& canvas, int x_offset, int y_offset) const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channels; ++c) {
                canvas.setPixel(x + x_offset, y + y_offset, c, getPixel(x, y, c));
            }
        }
    }
}

bool Image::load(const std::string &filepath) {
    if (filepath.ends_with(".png")) {
        return Load::loadPNG(filepath, *this);
    } else if (filepath.ends_with(".jpg") || filepath.ends_with(".jpeg")) {
        return Load::loadJPEG(filepath, *this);
    }
    return false;
}

bool Image::save(const std::string &filepath) {
    if (filepath.ends_with(".png")) {
        return Save::savePNG(filepath, *this);
    } else if (filepath.ends_with(".jpg") || filepath.ends_with(".jpeg")) {
        return Save::saveJPEG(filepath, *this);
    }
    return false;
}

void Image::setData(int w, int h, int ch, unsigned char* d) {
    if (data != nullptr) {
        delete[] data; 
    }
    width = w;
    height = h;
    channels = ch;
    data = new unsigned char[w * h * ch]; 
    std::copy(d, d + (w * h * ch), data); 
}

void Image::show() const {
    std::string temp_filepath;
#ifdef _WIN32
    char temp_name[L_tmpnam];
    std::tmpnam(temp_name);
    temp_filepath = std::string(temp_name) + ".png";
#elif __APPLE__ || __linux__
    std::string temp_dir = fs::temp_directory_path();
    temp_filepath = temp_dir + "/kalam_temp_image.png";
#else
    std::cerr << "Unsupported operating system for displaying the image." << std::endl;
    return;
#endif

    if (!Save::savePNG(temp_filepath, *this)) {
        std::cerr << "Failed to save the temporary image for display." << std::endl;
        return;
    }

    std::string command;
#ifdef _WIN32
    command = "start " + temp_filepath;
#elif __APPLE__
    command = "open " + temp_filepath;
#elif __linux__
    command = "xdg-open " + temp_filepath;
#endif

    int result = std::system(command.c_str());
    if (result != 0) {
        std::cerr << "Failed to open the image with the default application." << std::endl;
    }

    fs::remove(temp_filepath); 
}

} 
