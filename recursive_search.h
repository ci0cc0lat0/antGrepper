#include "cstdio"
#include "iostream"
#include "string"
#include "vector"
#include "filesystem"
#include "fstream"

using namespace std;
namespace fs  = filesystem;

namespace grep{
    // returns to check if a given path is to the given extention
    bool is_extension(const fs:: path, string);

    // A function fed a path, a file extension, and a file to write out to. Writes where called.
    void recursive_search(const fs::path, string, ofstream&);

    // A function fed a path, a file extension, and a file to write out to.
    void recursive_search(const fs::path, string);
}