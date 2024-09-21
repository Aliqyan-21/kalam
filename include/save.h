#ifndef SAVE_H
#define SAVE_H

#include <string>
#include "image.h" 

namespace kalam {
class Save {
public:
    static bool savePNG(const std::string& filepath, const Image& image);
    static bool saveJPEG(const std::string& filepath, const Image& image);
};
} // namespace kalam

#endif
