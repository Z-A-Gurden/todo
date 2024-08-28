#include <iostream>
#include <string>
#include <fstream>
#include "file.h"
#include "headers.h"

void add_to_list()
{     
    //creates list if not present, file is opened in append so as to not overwrite the original and therefore erase all other goals
    std::ofstream out{dir / "list.txt", std::ios::app};
    if(!out)
    {
        std::cerr << "File failed to open!\n";
        return;
    }
    std::cout << "What goal would you like to add?\n";
    std::string goal{};
    std::getline(std::cin >> std::ws, goal);
    out << goal + '\n';
    out.close();
}