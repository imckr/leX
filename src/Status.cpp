#include "Status.h"
#include "Add.h"

using namespace std;


void Status::print_status() {

// Scanning the Index file

        string indexPath = ".lex/index";


        ifstream indexFile(indexPath);

        if(!indexFile.is_open()) { cout << "Cannot Open file for checking!" << std::endl; return;}

        set<string> prevFiles;
        set<string> currFiles;
        string filePath;

        while(getline(indexFile, filePath)){
                prevFiles.emplace(filePath);
        }

        indexFile.close();

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

// For Deleted files

        vector<string> deletedFiles;

        for (auto& prev : prevFiles) {
                // If this file from prevFiles is NOT in currFiles -> it was deleted
                if (currFiles.find(prev) == currFiles.end()) {
                        //std::cout << "Deleted file: " << prev << "\n";
                        deletedFiles.push_back(prev);
                }
        }

// For New Files

        vector<string> untracked_files;

        for (auto& curr : currFiles) {
                if (prevFiles.find(curr) == prevFiles.end()) {
                        untracked_files.push_back(curr);
                }
        }

// Display

	for(auto untracked_file : untracked_files) {
		cout << "Untracked Files : " << untracked_file << endl;
	}

	for(auto deletedFile : deletedFiles) {
		cout << "Deleted File : " << deletedFile << endl;
	}

}

bool Status::check_status() {

	string indexPath = ".lex/index";


        ifstream indexFile(indexPath);
	string filePath;
	int index_file_count = 0;

	while(getline(indexFile, filePath)){
                index_file_count++;
        }

        indexFile.close();

	cout << index_file_count << endl;

	return true;

}
