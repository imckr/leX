#include "blobing.h"
#include "compress.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <openssl/sha.h>
// using namespace std;

namespace fs = std::filesystem;

// Function to compute SHA-1 hash of file contents
std::string Blober :: computeSHA1(const std::string &content)
{
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1(reinterpret_cast<const unsigned char *>(content.c_str()), content.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
        ss << std::hex << (hash[i] < 16 ? "0" : "") << (int)hash[i];
    }
    return ss.str();
}

/*

// Function to create a blob from a file
void Blober :: createBlob(const std::string &filePath, const std::string &blobDir)
{
    std::ifstream file(filePath);
    if (!file)
    {
        std::cerr << "Error: Cannot open file " << filePath << std::endl;
        return;
    }

    // Read file contents
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    Compress cm;
    std::string comp_content = cm.compressString(content);
    std::cout<<"Content size - "<<content.size()<<std::endl;
    std::cout<<"Compressed Content size - "<<comp_content.size()<<std::endl;

    // Compute SHA-1 hash
    std::string hash = computeSHA1(content);
    std::string hash_mod = hash.substr(2);
    std::string blobPath = blobDir + "/" + hash[0] + hash[1] + "/" + hash_mod;
    //std::cout<<blobPath<<std::endl;
    //std::cout<<hash_mod<<"  "<<hash<<std::endl;

    // Create the blob directory if it doesn't exist
    fs::create_directories(blobDir);
    fs::create_directories((blobDir + "/" + hash.substr(0,2)));

    // Write content to the blob file
    std::ofstream blobFile(blobPath);
    if (!blobFile)
    {
        std::cerr << "Error: Cannot create blob file" << std::endl;
        return;
    }
    blobFile << comp_content;
    blobFile.close();

    std::cout << "Blob created: " << blobPath << std::endl;
}
*/
