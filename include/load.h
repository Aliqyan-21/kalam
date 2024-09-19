#ifndef LOAD_H
#define LOAD_H

#include <string>

namespace kalam {
class Load {
public:
  bool loadPNG(const std::string &filepath);
  bool loadJPEG(const std::string &filepath);
};
} // namespace kalam

#endif
