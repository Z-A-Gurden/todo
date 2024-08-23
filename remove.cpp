#include <fstream>
#include <iostream>
#include "headers.h"

void remove_line()
{
    std::ifstream in{"list.txt"};
    std::ofstream temp_list{"temp.txt"};

    read_list();
    std::cout << "Enter the number at the start of the line which you want to remove.\n";
    int num{};
    std::cin >> num;

    //line is procedurally overwritten by a line of list.txt per iteration
    //if prefix num of line == to user choice(num), then that line won't be written into the temp file
    //i is incremented and compared with num to determine the truth of the if statement
    std::string line{};
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