#include <iostream>
#include <fstream>
#include "file.h"
#include "headers.h"

void mark_as_complete()
{
    const std::string Checkmark{"\xe2\x98\x91"};
    std::string line{};
    std::ifstream in{dir / "list.txt", std::ios::app};
    if(!in)
    {
        std::cerr << "File failed to open!\n";
        return;
    }
    std::ofstream temp_list{dir / "temp.txt"};
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
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Whoops, looks like that line does not exist. Try again.\n";
        std::cin >> mark;
    }

    //reading from in multiple times in one file sets file pointer to end leading to no data being written later, this sets it back to beginning
    in.clear();
    in.seekg(0);

    //this section tests if the line selected has already been marked, if not it will be marked
    int i{1};
    while(getline(in, line))
    {
        if(i == mark)
        {
            if(line.find(Checkmark) != std::string::npos) 
            {
                std::cout << "This goal has already been marked complete!\n";
                temp_list << line << '\n';
            }
            else temp_list << line << ' ' << Checkmark << '\n';
        }
        else temp_list << line << '\n';
        ++i;
    }
    in.close();
    temp_list.close();
    rename(dir / "temp.txt", dir / "list.txt");
}