#include "Menu.h"
#include <iostream>

namespace Menu
{
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

namespace createNewNetwork
{
std::string nameNetwork()
    {
        std::string network_name;

        std::cout << "Enter a name for this Netowrk to save its data: ";
        std::cin >> network_name;
        
        return network_name;
    }


int enterNumOfLayers()
    {
        int num_layers = 0;

        std::cout << "Enter number of Layers for the Network to be: ";
        std::cin >> num_layers;

        return num_layers;
    }

int enterInputLayerSize()
    {
        int input_layer_size = 0;

        std::cout << "Enter size of input layer: ";
        std::cin >> input_layer_size;

        return input_layer_size;
    }

int enterLayerSize(const int& layerNum)
    {
        int layer_size = 0;

        std::cout << "Enter size of layer " << layerNum << ": ";
        std::cin >> layer_size;

        return layer_size;

    }



LayerType enterLayerType(const int& layerNum)
    {
    int choiceInt = 0;

    Menu::createNewNetwork::displayLayerTypes();
    std::cout << "Select Layer Type for layer " << layerNum << ": ";
    std::cin >> choiceInt;

    std::cout << '\n';


    // convert to enum class
    return static_cast<LayerType>(choiceInt);
    }

void displayLayerTypes()
    {
        std::cout << '\n';
        std::cout << 
        "           Layer Types         \n"
        "---------------------------------\n"
        "1. Dense Layer\n"
        "2. Recurrent Layer\n\n";
    }

void displayActivationTypes()
    {
        {
            std::cout << '\n';
            std::cout << 
            "        Activation Functions     \n"
            "---------------------------------\n"
            "1. Sigmoid\n"
            "2. Relu\n\n";
        }
    }

ActivationFunction enterActivationFunction(const int& layerNum)
{
    int choiceInt = 0;

    Menu::createNewNetwork::displayActivationTypes();
    std::cout << "Select Activation function for layer " << layerNum << ": ";
    std::cin >> choiceInt;

    std::cout << '\n';


    // convert to enum class
    return static_cast<ActivationFunction>(choiceInt);
    }
}


}
