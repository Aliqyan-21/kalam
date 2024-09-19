#include "image.h"
#include <cassert>

int main() {
  kalam::Image img;
  assert(img.load("test.png"));
  assert(img.save("output.png"));
  return 0;
}
