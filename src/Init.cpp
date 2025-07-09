#include "Init.h"

int Init::createFileStructure() {

    int ok = EXIT_FAILURE;

    string lex_dir = ".lex";

    // Creating Directory for config and tracking file stats.
    if (filesystem::create_directory(lex_dir))
    {
        // cout << "" << endl;
        if (filesystem::create_directory(".lex/objects") && filesystem::create_directory(".lex/refs") && filesystem::create_directory(".lex/temp"))
        {
            ofstream HeadFile(".lex/HEAD");
            ofstream IndexFile(".lex/index");
            ofstream lexAtt("./.lexattributes");
            ofstream lexign("./.lexignore");
            ofstream temp(".lex/temp/tempIndex");
            if (filesystem::create_directory(".lex/objects/refs") && filesystem::create_directory(".lex/objects/info"))
            {
                cout << "lex initialized" << endl;
                ok = EXIT_SUCCESS;
            }
            else
            {
                cerr << "Unable to create reference directories !" << endl;
            }
        }
        else
        {
            cerr << "Unable to create sub directories!" << endl;
        }
    }
    else
    {
        cout << "Reinitialized lex" << endl;
    }
    return ok;
}
