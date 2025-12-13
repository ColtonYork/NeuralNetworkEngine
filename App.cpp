#include "App.h"
#include "UI/Menu.h"

void App::run() const
{
    while (int choice = Menu::startMenu())
        {
            switch (choice)
                {
                    case 1:
                        {
                            Menu::create_new_network_selected();
                            continue;
                        }
                    case 2:
                        continue;
                        
                    default:
                        continue;
                }

        }

        return;
}
