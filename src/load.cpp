#include "load.h"
#include "image.h"
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace kalam {

bool Load::loadPNG(const std::string& filepath, Image& image) {
    int width, height, channels;
    unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
    
    if (!data) {
        return false; 
    }

    std::vector<unsigned char> imageData(data, data + (width * height * channels));
    image.setData(width, height, channels, std::move(imageData));

    stbi_image_free(data); 
    return true;
}

bool Load::loadJPEG(const std::string& filepath, Image& image) {
    int width, height, channels;
    unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
    
    if (!data) {
        return false; 
    }

    std::vector<unsigned char> imageData(data, data + (width * height * channels));
    image.setData(width, height, channels, std::move(imageData));

    stbi_image_free(data); 
    return true;
}

} // namespace kalam
