#ifndef FILE
#define FILE

#include<filesystem>
namespace fs = std::filesystem;
    
    //proc/self/exe is a unix/linux symbolic link pointing to the exe file path(todo)
    //so dir will initially be path/to/todo
    //.parent_path() will make it so it doesn't point to todo but rather the directory, and will therefore create the list in the directory of todo or append to it
    inline fs::path exe{fs::read_symlink("/proc/self/exe")};
    inline fs::path dir{exe.parent_path()};

#endif