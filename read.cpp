#include <iostream>
#include <fstream>
#include "file.h"
#include "headers.h"

void read_list()
{
    std::ifstream in{dir / "list.txt"};
    if(!in)
    {
        std::cerr << "File failed to open or doesn't exist! Try adding a goal first.\n";
        return;
    }
    std::string line{};
    //displays all lines of list.txt and prefixes them with a number
    //useful for selection of goals in different contexts
    int i{1};
    while(getline(in, line))
    {
        std::cout << i << ". " << line << '\n';
        ++i;
    }
    in.close();
}