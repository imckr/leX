#include <iostream>
#include "Init.h"
#include "Add.h"
#include "Status.h"
#include "decoder.h"

using namespace std;

int main (int argc, char const *argv[]) {

	string command = argv[1];

    	if(command == "init"){
        	Init fs;
		bool isInitialized = fs.createFileStructure();
		if(isInitialized) {
	    		std::cout << "Created" << std::endl;
			//std::cerr << "Unable to Initialize" << std::endl;
		}
    	} else if (command == "add") {
		string path = argv[2];
		string newpath = "./";
		newpath.append(path);
		Add add;
		bool is_done = add.Stage(newpath);
		if(is_done){ std::cout << "Done 4" << std::endl; }
	} else if (command == "status") {

		Status s;
		s.print_status();

		cout << endl << "----------------------------------------------" << endl << endl;
		s.check_status();

	} else if(command == "cat-file") {

		Decoder decoding;
		std::string file_content = decoding.decode_content(argv[2]);
		std::cout << file_content << std::endl;

	}

	return 0;
}
