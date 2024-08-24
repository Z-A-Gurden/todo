#include <fstream>
#include <iostream>
#include "headers.h"

void remove_line()
{
    std::string line{};
    std::ifstream in{"list.txt"};
    if(!in)
    {
        std::cerr << "File failed to open!\n";
        return;
    }
    std::ofstream temp_list{"temp.txt"};
    if(!temp_list)
    {
        std::cerr << "File failed to open!\n";
        return;
    }

    read_list();

    //checks if user input is in range of the potential options
    int n_lines{};
    while(getline(in, line))
    {
        ++n_lines;
    }
    std::cout << "Enter the number at the start of the line which you want to remove.\n";
    int num{};
    std::cin >> num;
    while(num > n_lines || num <= 0)
    {
    std::cout << "Woops, looks like line " << num << " doesn't exist\n";
    std::cin >> num;
    }

    //reading from in multiple times in one file sets file pointer to end leading to no data being written later, this sets it back to beginning
    in.clear();
    in.seekg(0);

    //line is procedurally overwritten by a line of list.txt per iteration
    //if prefix num of line == to user choice(num), then that line won't be written into the temp file
    //i is incremented and compared with num to determine the truth of the if statement
    int i{1};
    while(getline(in, line))
    {
        if(i != num) 
        {
            temp_list << line << '\n';
        }
        ++i;
    }

    //list file is destroyed and temp file is renamed to list.txt, replacing the original
    temp_list.close();
    in.close();
    remove("list.txt");
    rename("temp.txt", "list.txt");
}