#include "image.h"
#include "load.h"
#include "save.h"

namespace kalam {

bool Image::load(const std::string& filepath) {
    if (filepath.ends_with(".png")) {
        return Load::loadPNG(filepath, *this); 
    } else if (filepath.ends_with(".jpg") || filepath.ends_with(".jpeg")) {
        return Load::loadJPEG(filepath, *this); 
    }
    return false;
}

bool Image::save(const std::string& filepath) {
    if (filepath.ends_with(".png")) {
        return Save::savePNG(filepath, *this); 
    } else if (filepath.ends_with(".jpg") || filepath.ends_with(".jpeg")) {
        return Save::saveJPEG(filepath, *this); 
    }
    return false;
}

void Image::setData(int w, int h, int ch, std::vector<unsigned char>&& d) {
    width = w;
    height = h;
    channels = ch;
    data = std::move(d);
}

} // namespace kalam
