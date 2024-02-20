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
            cerr << "Flags: " << " -p"<<" for an out file" << std::endl;
            /* cerr << "Hint: Running the command without any flags and '> <filename.txt>' at the end will redirect output to that file" << endl;
            cerr << "Hint: Using . or .. as the path argument will search the current directory or the above parent directory respectively" << endl;
            cerr << "e.g: antGrep . .pdf > out.txt" << endl; */
            cerr << "Hint: " <<  "antGrep . <filetype> to serach current directory recursively" << endl;
            cerr << "Hint: " <<  "antGrep .. <filetype> to serach the parent directory recursively" << endl;
            cerr << "Hint: " <<  "antGrep <path> <filetype> > <outfile> to redirect input to the outfile" << endl;

            return 0;
        }
        cerr << "Usage: " << argv[0] << " -flags <path> <filetype>" << std::endl;
        cerr << "Type -h for help" << std::endl;
        return 1;
        break;
    case 3:
        break;
    case 4:
        if(strcmp(argv[1],"-p") == 0){
            ofstream ffile;
            ffile.open("out.txt");
            grep::recursive_search(argv[2],argv[3],ffile);
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
