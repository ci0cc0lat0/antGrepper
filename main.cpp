#include "cstdio"
#include "iostream"
#include "string"
#include "vector"
#include "filesystem"
#include "fstream"
#include <cstring>

#include "recursive_search.h"
using namespace std;
namespace fs  = filesystem;

int main(int argc, char *argv[]){
    switch (argc)
    {
    case 1:
        cerr << "Usage: " << argv[0] << " -flags <path> <filetype>" << std::endl;
        cerr << "Type -h for help" << std::endl;
        return 1;
        break;
    case 2:
        if(strcmp(argv[1],"-h") == 0){
            cerr << "A tool for recursivly searching a path for all desired filetypes\n" << endl;
            cerr << "Usage: " << argv[0] << " -flags <path> <filetype>" << std::endl;
            cerr << "Usage example: " << argv[0] << " . .pdf\n" << std::endl; 

            cerr << "Flags: " << " -p"<<" for an out file" << std::endl;
            //cerr << "Flags: " << " -r"<<" to print current directory files' relative path\n" << std::endl;
            cerr << "Flags: " << " -w"<<" to print current directory files' absolute path\n" << std::endl;


            /* cerr << "Hint: Running the command without any flags and '> <filename.txt>' at the end will redirect output to that file" << endl;
            cerr << "Hint: Using . or .. as the path argument will search the current directory or the above parent directory respectively" << endl;
            cerr << "e.g: antGrep . .pdf > out.txt" << endl; */
            cerr << "Hint: " <<  "antGrep . <filetype> to serach current directory recursively" << endl;
            cerr << "Hint: " <<  "antGrep .. <filetype> to serach the parent directory recursively" << endl;
            cerr << "Hint: " <<  "antGrep <path> <filetype> > <outfile> to redirect output to the outfile" << endl;

            return 0;
        }
        cerr << "Usage: " << argv[0] << " -flags <path> <filetype>" << endl;
        cerr << "Type -h for help" << endl;
        return 1;
        break;
    case 3:
        // We run any errors through the source rather than switch for now
        break;
    case 4:
        if (strcmp(argv[1],"-p") == 0){
            ofstream ffile;
            ffile.open("out.txt");
            grep::recursive_search(argv[2],argv[3],ffile);
            ffile.close(); 
        }
        else if(strcmp(argv[1],"-w") == 0){
            grep::recursive_search_w(argv[2],argv[3]);
        }
        return 0;
        break;
    case 5: 
        if (((strcmp(argv[1],"-w") == 0) && (strcmp(argv[2],"-p") == 0))
         || ((strcmp(argv[1],"-p") == 0) && (strcmp(argv[2],"-w") == 0)))
         {

            ofstream ffile;
            ffile.open("out.txt");
            grep::recursive_search_wp(argv[3],argv[4],ffile);
            ffile.close();
        }

        return 0;
        break;
    default:
        break;
    }
    
    ofstream ffile;
    ffile.open("out.txt");
    grep::recursive_search(argv[1],argv[2]);
    ffile.close(); 
    return 0;
}

