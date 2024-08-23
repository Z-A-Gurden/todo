#include <iostream>
#include <string>
#include <fstream>
#include "headers.h"

void add_to_list()
{   
    //creates list if not present, file is opened in append so as to not overwrite the original and therefore erase all other goals
    std::ofstream out{"list.txt", std::ios::app};
    std::cout << "What goal would you like to add?\n";
    std::string goal{};
    std::getline(std::cin >> std::ws, goal);
    out << goal + '\n';
    out.close();
}