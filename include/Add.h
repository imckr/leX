#include <bits/stdc++.h>
#include <openssl/sha.h>
#include "compress.h"
//#include <iostream>
#include <chrono>
//#include <format> // Requires C++20
#include <ctime>

namespace fs = std::filesystem;

class Add {

public :

	std::string Read_Directory_files(const fs::path& path);
	std::string ComputeSHA1(const std::string &content);
	bool UpdateIndex(const std::string &file_or_directory);
	bool Stage(const std::string &path);
	std::string Create_object(const std::string &file_path);

};
