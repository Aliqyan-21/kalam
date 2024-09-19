#ifndef SAVE_H
#define SAVE_H

#include <string>

namespace kalam {
class Save {
public:
  bool savePNG(const std::string &filepath);
  bool saveJPEG(const std::string &filepath);
};
} // namespace kalam

#endif
