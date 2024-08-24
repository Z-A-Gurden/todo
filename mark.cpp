#include <iostream>
#include <fstream>
#include "headers.h"

void mark_as_complete()
{
    const std::string Checkmark{"\xe2\x98\x91"};
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

    //checks if user input is in range of the potential options
    int n_lines{};
    while(getline(in, line))
    {
        ++n_lines;
    }
    read_list();
    std::cout << "Enter the number corresponding to the goal you wish to mark as complete.\n";
    int mark{};
    std::cin >> mark;
    while(mark > n_lines || mark <= 0)
    {
        std::cout << "Whoops, looks like that  line does not exist. Try again.\n";
        std::cin >> mark;
    }

    //reading from in multiple times in one file sets file pointer to end leading to no data being written later, this sets it back to beginning
    in.clear();
    in.seekg(0);

    while(getline(in, line))
    {
        if(i == mark) temp_list << line << ' ' << Checkmark << '\n';
        else temp_list << line << '\n';
        ++i;
    }
    in.close();
    temp_list.close();
    rename("temp.txt", "list.txt");
}