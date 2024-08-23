#include <iostream>
#include "headers.h"

void menu()
{
    //user selects action in this loop
    int option{};
    while(true)
    {
        std::cout << "Welcome to your todo list, what do you want to do?\n 1) List goals\n 2) Add goal\n 3) Mark goal complete\n 4) Remove goal from list\n 5) Erase list\n";
        std::cin >> option;
        if(option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
        {
            std::cout << "Invalid choice, please try again.\n";
            continue;
        }
        else break;
    }

    //action matched with function here
    switch(option)
    {
        case 1:
            read_list();
            break;
        case 2:
            add_to_list();
            break;
        case 3:
            mark_as_complete();
            break;
        case 4:
            remove_line();
            break;
        case 5:
            erase_list();
            break;
    }
}