#include "UI/Menu.h"
#include <iostream>


int main(const int argc, const char *argv[])
{

    int choice;

    //user selects 'create new network'
    while (choice = Menu::startMenu())
        {
            Menu::create_new_network_selected();
        }
}