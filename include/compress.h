#include <iostream>
#include <string>
#include <vector>
#include <zlib.h>

class Compress {

public :
    std::string compressString(const std::string& str);
    std::string decompressString(const std::string &compressed, size_t expectedSize);
};
