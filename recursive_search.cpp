#include "recursive_search.h"


bool grep::is_extension(const fs::path path, string extension){
    if(path.extension().string() == extension) return true;
    else return false;
}

// For -p flag
void grep::recursive_search(const fs::path path, string ext, ofstream& output_file){

    vector<fs::directory_entry> dirs;
    for(const auto& entry: fs::directory_iterator(path)){
        if(entry.is_directory()){
            dirs.push_back(entry);
        }
        else if(grep::is_extension(entry,ext)){
            fs::path out_path = entry.path();
            std::string absolute = fs::canonical(out_path).string();
            output_file << absolute << "\n";
            
        }
    }
    
    for(const auto& dir: dirs){
        grep::recursive_search(dir, ext, output_file);
    }
}

// Without any flags
void grep::recursive_search(const fs::path path, string ext){
    vector<fs::directory_entry> dirs;
    for(const auto& entry: fs::directory_iterator(path)){
        if(entry.is_directory()){
            dirs.push_back(entry);
        }
        // This does not give absolute path, gives current path + file, doesnt show deeper
        else if(grep::is_extension(entry,ext)){
            fs::path out_path = entry.path();

            fs::path absolute_path = fs::canonical(out_path);
            std::string remove_quotes = absolute_path.string();
            std::cout << remove_quotes << "\n";
        }
    }
    
    for(const auto& dir: dirs){
        grep::recursive_search(dir, ext);
    }
}

void grep::recursive_search_wp(const fs::path path, string ext, ofstream& output_file){
    vector<fs::directory_entry> dirs;
    for(const auto& entry: fs::directory_iterator(path)){
        if(entry.is_directory()){
            dirs.push_back(entry);
        }
        else if(grep::is_extension(entry,ext)){
            fs::path out_path = entry.path();
            //std::string absolute = fs::absolute(out_path.filename()).string();
            output_file << out_path.filename().string() << "\n";
            
        }
    }
    
    for(const auto& dir: dirs){
        grep::recursive_search_wp(dir, ext, output_file);
    }
}

void grep::recursive_search_w(const fs::path path, string ext){
    vector<fs::directory_entry> dirs;
    for(const auto& entry: fs::directory_iterator(path)){
        if(entry.is_directory()){
            dirs.push_back(entry);
        }
        else if(grep::is_extension(entry,ext)){
            std::cout << entry.path().filename().string() << "\n";
            
        }
    }
    
    for(const auto& dir: dirs){
        grep::recursive_search_w(dir, ext);
    }
}