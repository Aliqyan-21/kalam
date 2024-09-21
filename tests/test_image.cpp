#include "image.h"
#include <cassert>
#include <iostream>

int main(void) {
  kalam::Image img;
  if (!img.load("testImages/dust.png")) {
    std::cerr << "Failed to load PNG image" << std::endl;
    return 1;
  }
  if (!img.save("testImages/opng.png")) {
    std::cerr << "Failed to save PNG image" << std::endl;
    return 1;
  }
  if (!img.load("testImages/test.jpg")) {
    std::cerr << "Failed to load JPEG image" << std::endl;
    return 1;
  }
  if (!img.save("testImages/ojpg.jpg")) {
    std::cerr << "Failed to save JPEG image" << std::endl;
    return 1;
  }
  return 0;
}
