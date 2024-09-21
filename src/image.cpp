#include "kalam.h"
#include "load.h"
#include "save.h"
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace kalam {

bool Image::load(const std::string &filepath) {
  if (filepath.ends_with(".png")) {
    return Load::loadPNG(filepath, *this);
  } else if (filepath.ends_with(".jpg") || filepath.ends_with(".jpeg")) {
    return Load::loadJPEG(filepath, *this);
  }
  return false;
}

bool Image::save(const std::string &filepath) {
  if (filepath.ends_with(".png")) {
    return Save::savePNG(filepath, *this);
  } else if (filepath.ends_with(".jpg") || filepath.ends_with(".jpeg")) {
    return Save::saveJPEG(filepath, *this);
  }
  return false;
}

void Image::setData(int w, int h, int ch, std::vector<unsigned char> &&d) {
  width = w;
  height = h;
  channels = ch;
  data = std::move(d);
}

void Image::show() const {
  std::string temp_filepath;
#ifdef _WIN32
  char temp_name[L_tmpnam];
  std::tmpnam(temp_name);
  temp_filepath = std::string(temp_name) + ".png";
#elif __APPLE__ || __linux__
  std::string temp_dir = std::filesystem::temp_directory_path();
  temp_filepath = temp_dir + "/kalam_temp_image.png";
#else
  std::cerr << "Unsupported operating system for displaying the image."
            << std::endl;
  return;
#endif

  if (!Save::savePNG(temp_filepath, *this)) {
    std::cerr << "Failed to save the temporary image for display." << std::endl;
    return;
  }

  std::string command;
#ifdef _WIN32
  command = "start " + temp_filepath;
#elif __APPLE__
  command = "open " + temp_filepath;
#elif __linux__
  command = "xdg-open " + temp_filepath;
#endif

  int result = std::system(command.c_str());
  if (result != 0) {
    std::cerr << "Failed to open the image with the default application."
              << std::endl;
  }

  // to delete the temp file that was created to show the image
  std::filesystem::remove(temp_filepath);
}

} // namespace kalam
