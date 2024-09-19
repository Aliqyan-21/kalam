#include "load.h"
#include <png.h>
#include <jpeglib.h>
#include <cstdio>

namespace kalam {

bool Load::loadPNG(const std::string& filepath) {
    FILE* file = fopen(filepath.c_str(), "rb");
    if (!file) return false;

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) {
        fclose(file);
        return false;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        png_destroy_read_struct(&png, nullptr, nullptr);
        fclose(file);
        return false;
    }

    if (setjmp(png_jmpbuf(png))) {
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(file);
        return false;
    }

    png_init_io(png, file);
    png_read_info(png, info);
    png_destroy_read_struct(&png, &info, nullptr);
    fclose(file);
    return true;
}

bool Load::loadJPEG(const std::string& filepath) {
    FILE* file = fopen(filepath.c_str(), "rb");
    if (!file) return false;

    jpeg_decompress_struct cinfo;
    jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(file);
    return true;
}

}
