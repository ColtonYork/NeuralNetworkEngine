#include "Menu.h"
#include <iostream>

namespace Menu
{
std::string nameNetwork()
    {
        std::string network_name;

        std::cout << "Enter a name for this Netowrk to save its data: ";
        std::cin >> network_name;
        
        return network_name;
    }

int startMenu()
    {
        std::cout << 
        "        NEURAL NETWORK ENGINE\n" 
        "----------------------------------------- \n" 
        "1. Create new network\n" 
        "2. Load a Network\n";

        int choice = 0;
        std::cin >> choice;
        if (choice > 2 || choice < 0) 
            return 0;

        return choice;
            
    }

}