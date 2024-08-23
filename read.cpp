#include <iostream>
#include <fstream>
#include "headers.h"

void read_list()
{
    std::ifstream in{"list.txt"};
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