#include <cstdio>
#include <string>

std::string DetectType(const unsigned char* data, size_t size) {
    if (size >= 2) {
        if (data[0] == 0x50 && data[1] == 0x4b) {
            return "zip";
        }
    }
    if (size >= 3) {
        if (data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff) {
            return "jpg";
        }
    }
    if (size >= 4) {
        if (data[0] == 0x25 && data[1] == 0x50 && data[2] == 0x44 && data[3] == 0x46) {
            return "pdf";
        }
    }
    return "other";
}