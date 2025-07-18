#include <bits/stdc++.h>
#include <ctime>
#include <chrono>
//#include "Add.h"

using namespace std;
//namespace fs = filesystem;
/*
bool is_New() {

//working...

// Scanning the Index file

	string indexPath = ".lex/index";


        ifstream indexFile(indexPath);

        if(!indexFile.is_open()) { cout << "Cannot Open file for checking!" << std::endl; return false;}

        vector<string> prevFiles;
        set<string> currFiles;
	string filePath;

        while(getline(indexFile, filePath)){
                prevFiles.push_back(filePath);
        }

        indexFile.close();

// Index file Reading Complete


// Reading Current All files Exists

	const std::string path = ".";
	fs::path AllfilesPath = path;
	Add readfile;

        std::string current_files = readfile.Read_Directory_files(AllfilesPath);
        istringstream iss(current_files);
        string file;

        while(getline(iss, file)){
                currFiles.emplace(file);
        }

// Comparison Logic

// For Deleted files

	vector<string> deletedFiles;

	for (const auto& prev : prevFiles) {
        	// If this file from prevFiles is NOT in currFiles -> it was deleted
        	if (currFiles.find(prev) == currFiles.end()) {
            		//std::cout << "Deleted file: " << prev << "\n";
			deletedFiles.push_back(curr);
        	}
    	}

// For New Files

	vector<string> newFiles;

	for (const auto& curr : currFiles) {
 	  	if (prevFiles.find(curr) == prevFiles.end()) {
        		newFiles.push_back(curr);
    		}
	}



//-------------------------
	for(auto file : allfiles) {
                cout << file << " --- " << endl;
       	}

        return true;

}

*/
int main() {

//	bool res = is_New();

/*	std::time_t now = time(0);
	std::tm *ltm = localtime(&now); 
	std::String date = ltm->tm_mday + "/" + (1 + ltm->tm_mon) + "/" + (1900 + ltm->tm_year) + " " + (1 + ltm->tm_hour) + ":" + (1 + ltm->tm_min) + ":" + (1 + ltm->tm_sec);
*/

	std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);

        //std::string time = "Date: " + (now->tm_year + 1900) + (now->tm_mon + 1) + now->tm_mday + '\n';

	char mbstr[100];
 	std::strftime(mbstr, 100, "%d/%m/%Y %T", std::localtime(&t));
 	std::string time (mbstr);
	std::cout << time << std::endl;

    	return 0;
}
