#include <iostream>
#include <fstream>

void erase_list()
{
    //simply opens in write mode, overwriting the list and clearing all data
    std::ofstream out{"list.txt"};
    if(!out)
    {
        std::cerr << "File failed to open!\n";
        return;
    }
    out.close();
}