#include <iostream>
#include <fstream>
#include "headers.h"

void mark_as_complete()
{
    read_list();
    std::cout << "Enter the number corresponding to the goal you wish to mark as complete.\n";
    int mark{};
    std::cin >> mark;
    std::string line{};
    std::ifstream in{"list.txt", std::ios::app};
    if(!in)
    {
        std::cerr << "File failed to open!\n";
        return;
    }
    int i{1};
    std::ofstream temp_list{"temp.txt"};
    if(!temp_list)
    {
        std::cerr << "File failed to open!\n";
        return;
    }
    while(getline(in, line))
    {
        if(i == mark) temp_list << line << ' ' << "\xe2\x98\x91" << '\n';
        else temp_list << line << '\n';
        ++i;
    }
    in.close();
    temp_list.close();
    rename("temp.txt", "list.txt");
}