#include <bits/stdc++.h>
#include <zlib.h>
//#include "compress.h"

class Decoder {
public :

	std::string decode_content(char const *fileName);
	std::string decompressString(const std::string& compressed, size_t expectedSize);
};
