#include "recursive_search.h"


bool grep::is_extension(const fs::path path, string extension){
    if(path.extension().string() == extension) return true;
    else return false;
}

void grep::recursive_search(const fs::path path, string ext, ofstream& output_file){

    vector<fs::directory_entry> dirs;
    for(const auto& entry: fs::directory_iterator(path)){
        if(entry.is_directory()){
            dirs.push_back(entry);
        }
        else if(grep::is_extension(entry,ext)){
            output_file << entry.path().filename() << endl;
        }
    }
    
    for(const auto& dir: dirs){
        grep::recursive_search(dir, ext, output_file);
    }
}


void grep::recursive_search(const fs::path path, string ext){

    vector<fs::directory_entry> dirs;
    for(const auto& entry: fs::directory_iterator(path)){
        if(entry.is_directory()){
            dirs.push_back(entry);
        }
        else if(grep::is_extension(entry,ext)){
            std::cout << entry.path().filename() << endl;
        }
    }
    
    for(const auto& dir: dirs){
        grep::recursive_search(dir, ext);
    }
}