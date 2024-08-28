#include <iostream>
#include <fstream>
#include <filesystem>
#include "file.h"

void erase_list()
{
    //simply opens in write mode, overwriting the list and clearing all data
    std::ofstream out{dir / "list.txt"};
    if(!out)
    {
        std::cerr << "File failed to open!\n";
        return;
    }
    out.close();
}