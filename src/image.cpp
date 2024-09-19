#include "image.h"
#include "load.h"
#include "save.h"

namespace kalam {

bool Image::load(const std::string& filepath) {
    if (filepath.ends_with(".png")) {
        return Load::loadPNG(filepath);
    } else if (filepath.ends_with(".jpg") || filepath.ends_with(".jpeg")) {
        return Load::loadJPEG(filepath);
    }
    return false;
}

bool Image::save(const std::string& filepath) {
    if (filepath.ends_with(".png")) {
        return Save::savePNG(filepath);
    } else if (filepath.ends_with(".jpg") || filepath.ends_with(".jpeg")) {
        return Save::saveJPEG(filepath);
    }
    return false;
}
}
