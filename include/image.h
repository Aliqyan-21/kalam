#ifndef IMAGE_H
#define IMAGE_H

#include <string>

namespace kalam {

class Image {
public:
  Image() = default;
  Image(int w, int h, int ch);
  ~Image();

  bool load(const std::string &filepath);
  bool save(const std::string &filepath);
  void show() const;

  void setData(int w, int h, int ch, unsigned char *d);
  unsigned char getPixel(int x, int y, int channel) const;
  void setPixel(int x, int y, int channel, unsigned char value);
  bool isInBounds(int x, int y) const;
  bool isValid() const;

  int getWidth() const { return width; }
  int getHeight() const { return height; }
  int getChannels() const { return channels; }
  const unsigned char *getData() const { return data; }

  void copyToLargerCanvas(Image &canvas, int x_offset, int y_offset) const;

private:
  int width{0};
  int height{0};
  int channels{0};
  unsigned char *data{nullptr}; // Using raw memory instead of std::vector
};
} // namespace kalam

#endif
