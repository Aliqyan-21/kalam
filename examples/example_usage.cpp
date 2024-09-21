#include <iostream>
#include <kalam.h>

int main() {
  // this is how kalam will be used
  kalam::Image img;
  if (!img.load("pathtoimage/image.png")) {
    std::cout << "Image not loaded" << std::endl;
  } else {
    std::cout << "Image is loaded" << std::endl;
  }

  std::cout << "Displaying the image..." << std::endl;

  img.show();

  return 0;
}
