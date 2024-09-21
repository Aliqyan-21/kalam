#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

namespace kalam {
class Image {
public:
    bool load(const std::string &filepath);
    bool save(const std::string &filepath);
    void show() const;

    void setData(int w, int h, int ch, std::vector<unsigned char>&& d);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getChannels() const { return channels; }
    const std::vector<unsigned char>& getData() const { return data; }

private:
    int width{0};
    int height{0};
    int channels{0};
    std::vector<unsigned char> data;
};
} // namespace kalam

#endif
