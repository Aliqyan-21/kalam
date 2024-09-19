#include "kalam.h"
#include <iostream>

int main() {
  // this is how kalam will be used
  kalam::Kalam app;
  app.initialize();
  std::cout << "Kalam library initialized." << std::endl;
  return 0;
}
