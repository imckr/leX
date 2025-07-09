#include "decoder.h"


std::string Decoder::decompressString(const std::string& compressed, size_t expectedSize) {
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


std::string Decoder::decode_content(char const *fileName) {

    FILE *fr = fopen(fileName, "r");

    if (!fr) {
        std::cerr << "Unable to open file" << std::endl;
        exit(1);
    }

    std::string content, original_content;
    int c;

    while ((c = fgetc(fr)) != EOF) {
        content += static_cast<char>(c);  // Read file content into string
    }

    std::cout << content << std::endl;

    // Perform decoding (example: reversing the string)
    //std::reverse(content.begin(), content.end());

    //Compress deComp;
    original_content = decompressString(content, 4000);

    return original_content;
}
