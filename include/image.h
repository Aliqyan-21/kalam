#ifndef IMAGE_H
#define IMAGE_H

#include <string>

namespace kalam {
class Image {
public:
  bool load(const std::string &filepath);
  bool save(const std::string &filepath);
};
} // namespace kalam

#endif
