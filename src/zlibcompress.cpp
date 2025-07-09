#include "compress.h"

std::string Compress::compressString(const std::string& str) {
    uLong sourceLen = str.size();
    uLong destLen = compressBound(sourceLen);

    std::string compressed(destLen, '\0');
    if (compress(reinterpret_cast<Bytef*>(&compressed[0]), &destLen,
                 reinterpret_cast<const Bytef*>(str.data()), sourceLen) != Z_OK) {
        throw std::runtime_error("Compression failed!");
    }

    compressed.resize(destLen);
    return compressed;
}

std::string Compress::decompressString(const std::string& compressed, size_t expectedSize) {
   // std::vector<Bytef> decompressed(expectedSize + 100); // Extra space for safety
    std::string decompressed(expectedSize, '\0'); // Allocate space

    uLong destLen = decompressed.size();
    if (uncompress(reinterpret_cast<Bytef*>(&decompressed[0]), &destLen,
                   reinterpret_cast<const Bytef*>(compressed.data()), compressed.size()) != Z_OK) {
        throw std::runtime_error("Decompression failed!");
    }

    //return decompressed;
    return std::string(decompressed.begin(), decompressed.begin() + destLen);
}
