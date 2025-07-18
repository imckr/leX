#include "Add.h"

namespace fs = std::filesystem;
using namespace std;

std::string Add::Read_Directory_files(const fs::path& path) {

	std::string list = "";

	if (!fs::exists(path)) {
        	std::cerr << "File or Directory does not exist: " << path << std::endl;
        	return list;
    	}

	if(fs::is_directory(path)){

		for (const auto& entry : fs::recursive_directory_iterator(path)) {
        		//std::cout << (fs::is_directory(entry) ? "[DIR]  " : "[FILE] ") << entry.path() << '\n';
			if(!fs::is_directory(entry)) {
				list.append(fs::relative(entry.path(), "."));
				list.append("\n");
			}
    		}

//		std::cout << list;
	}
	if(fs::is_regular_file(path)){

		//std::ifstream indexFile(".lex/index");
		//std::string index << indexFile;
		//indexFile.close();
		//list.append(index);
		std::string filename = path;
		list.append(filename.substr(2));
		std::cout << filename.substr(2) << std::endl;
		list.append("\n");
	}

//	std::cout << res;

	return list;
}

std::string Add::ComputeSHA1(const std::string &content) {

	unsigned char hash[SHA_DIGEST_LENGTH];
	SHA1(reinterpret_cast<const unsigned char *>(content.c_str()), content.size(), hash);

	std::stringstream ss;
	for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
    	{
        	ss << std::hex << (hash[i] < 16 ? "0" : "") << (int)hash[i];
    	}
	//std::cout << ss.str() << std::endl;
    	return ss.str();

}

bool Add::UpdateIndex(const std::string &file_or_directory) {

	bool is_ok = false;

	std::set<std::string> files; // stores filenames {'xysz.drs', 'sffsfs.ess',.....}

	// Reading prev stagged files from IndexFile


	std::ifstream read_indexFile(".lex/index");
	std::string line;
	while(std::getline(read_indexFile, line)){
		files.emplace(line);
	}

	read_indexFile.close();
	line = "";


	// Reading current files to be stagged

	//std::set<string> currFiles;
	istringstream iss(file_or_directory);

	while(std::getline(iss, line)){
		files.emplace(line);
	}


	// Opening IndexFile for Writing the Filename to be Stagged


	std::ofstream write_indexFile(".lex/index");
	if(!write_indexFile) {
		std::cerr << "Cannot open file" << std::endl;
		return is_ok;
	}

	std::string filestring = "";
	for(auto file : files) {
		filestring.append(file);
		filestring.append("\n");
	}

	write_indexFile << filestring;

	write_indexFile.close();

	//-----------------------------------------------

	is_ok = true;
	return is_ok;
}


std::string Add::Create_object(const std::string &file_path){

	std::string result = "FAILURE";

	std::string object_directory = ".lex/objects";

	std::ifstream file(file_path);
    	if (!file)
    	{
        	std::cerr << "Error: Cannot open file " << file_path << std::endl;
        	return result;
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

//	auto now = std::chrono::system_clock::now();
//    	std::time_t time = std::chrono::system_clock::to_time_t(now);
    	//std::cout << "Current time: " << std::ctime(&time);
	std::time_t t = std::time(nullptr);
    	std::tm* now = std::localtime(&t);

//   	std::string time = "Date: " + (now->tm_year + 1900) + (now->tm_mon + 1) + now->tm_mday + '\n';

	char mbstr[100];
        std::strftime(mbstr, 100, "%d/%m/%Y %T", std::localtime(&t));
        std::string time (mbstr);

//	std::string time = "Date: " + to_string(now->tm_mday) + to_string()

	//istringstream time(std::ctime(&time));
    	std::string hash = ComputeSHA1(file_path + comp_content + time);
    	std::string hash_mod = hash.substr(2);
    	std::string file_blob_path = object_directory + "/" + hash[0] + hash[1] + "/" + hash_mod;
    	//std::cout<<file_blob_path<<std::endl;
    	//std::cout<<hash_mod<<"  "<<hash<<std::endl;

    	// Create the blob directory if it doesn't exist
    	//fs::create_directories(object_directory);
    	fs::create_directories((object_directory + "/" + hash.substr(0,2)));

    	// Write content to the blob file
    	std::ofstream fileblob(file_blob_path);
    	if (!fileblob)
    	{
        	std::cerr << "Error: Cannot create blob file" << std::endl;
        	return result;
    	}
    	fileblob << comp_content;
    	fileblob.close();

    	std::cout << "Blob created: " << file_blob_path << std::endl;

	result = "SUCCESS";
	return result;
}


bool Add::Stage(const std::string &path) {

	bool is_done = false;

	fs::path pathToScan = path;
	std::string list = Read_Directory_files(pathToScan);
	//std::string blob = a1.GenerateBlob(list);
	UpdateIndex(list);

	istringstream iss(list);
	std::string file_name;
        while(std::getline(iss, file_name)){
                std::string result = Create_object(file_name);
		std::cout << result << std::endl;
        }
	is_done = true;

	return is_done;

}
