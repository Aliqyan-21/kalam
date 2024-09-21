#include "save.h"
#include "image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

namespace kalam {

bool Save::savePNG(const std::string& filepath, const Image& image) {
    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();
    const std::vector<unsigned char>& data = image.getData();

    int success = stbi_write_png(filepath.c_str(), width, height, channels, data.data(), width * channels);
    
    return success != 0; 
}

bool Save::saveJPEG(const std::string& filepath, const Image& image) {
    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();
    const std::vector<unsigned char>& data = image.getData();

    int quality = 90; 
    int success = stbi_write_jpg(filepath.c_str(), width, height, channels, data.data(), quality);

    return success != 0; 
}

} // namespace kalam
