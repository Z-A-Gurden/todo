#include <iostream>
#include <fstream>

void erase_list()
{
    //simply opens in write mode, overwriting the list and clearing all data
    std::ofstream out{"list.txt"};
    out.close();
}