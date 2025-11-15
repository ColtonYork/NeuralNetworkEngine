#include "Menu.h"
#include <iostream>

namespace Menu
{
std::string Menu::nameNetwork()
    {
        std::string network_name;

        std::cout << "Enter a name for this Netowrk to save its data: ";
        std::cin >> network_name;
        
        return network_name;
    }
}