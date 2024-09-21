#ifndef LOAD_H
#define LOAD_H

#include <string>
#include "image.h" 

namespace kalam {
class Load {
public:
    static bool loadPNG(const std::string& filepath, Image& image);
    static bool loadJPEG(const std::string& filepath, Image& image);
};
} // namespace kalam

#endif
