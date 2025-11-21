#include "Menu.h"
#include <fstream>
#include <iostream>

namespace Menu
{
    int startMenu()
    {
        std::cout << 
        "        NEURAL NETWORK ENGINE\n" 
        "----------------------------------------- \n" 
        "1. Create new network confiuguration\n" 
        "2. Train/Load a Network\n";

        int choice = 0;
        std::cin >> choice;
        if (choice > 2 || choice < 0) 
            return 0;

        return choice; 
    }

    bool create_new_network_selected()
    {
        NetworkConfig network_config;

            network_config.network_name = Menu::createNewNetwork::nameNetwork();
            network_config.layers = Menu::createNewNetwork::enterNumOfLayers();

            //input layer
            LayerConfig input_layer_config;
            input_layer_config.layerSize = Menu::createNewNetwork::enterInputLayerSize();
            network_config.layerData.push_back(input_layer_config);

            //rest of layers
            for (int i = 1; i < network_config.layers; i++)
                {
                    LayerConfig layer_config;

                    layer_config.layerSize = Menu::createNewNetwork::enterLayerSize(i);
                    layer_config.layer_type = Menu::createNewNetwork::enterLayerType(i);
                    layer_config.activation_function = Menu::createNewNetwork::enterActivationFunction(i);

                    network_config.layerData.push_back(layer_config);
    
                }
        
        network_config.batch_size = Menu::createNewNetwork::enter_batch_size();
        network_config.learning_rate = Menu::createNewNetwork::enter_learning_rate();
        network_config.input_data_file_path = Menu::createNewNetwork::enter_input_data_file_path();

        if (Menu::createNewNetwork::networked_created(network_config))
                return 1;

        std::cout << "\nNetwrok Discarded. Returning to menu\n";
        return 0;

        

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
                std::cout << '\n';
                std::cout << 
                "        Activation Functions     \n"
                "---------------------------------\n"
                "1. Sigmoid\n"
                "2. Relu\n\n"; 
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
    
    std::string enter_input_data_file_path()
        {
            std::string input_data_path = "";
            std::ifstream input_stream;

            std::cout << "Enter file path to input data file.\n";
            std::cout << "  - File should only contain float values seperated by spaces or newline characters\n";
            std::cout << "  - File should contain as many float values as size as input vector\n";
            std::cout << "Enter file path to input data file or enter 'e' to see an example format file: ";

            std::cin >> input_data_path;

            if (input_data_path == "e" || input_data_path == "E")
                {
                    output_input_data_file_format();
                    std::cout << "Enter file path to input data file: ";
                    std::cin >> input_data_path;
                }

            input_stream.open(input_data_path);

            if (!input_stream.is_open())
                {
                    std::cout << "[ERROR][Could not open input data file given]\n";
                    input_stream.close();
                    return "error";
                }
            else 
                {
                    std::cout << "File successfuly loaded.\n";
                    input_stream.close();
                    return input_data_path;
                }

        }

    void output_input_data_file_format()
        {
            std::cout << "\n\n\n";
            std::cout << "0.123456\n";
            std::cout << "-1.53854\n";
            std::cout << "3.140000\n";
            std::cout << "4.234542\n";
            std::cout << "2.238493\n";
            std::cout << "\n\n\n";
        }


    float enter_learning_rate()
        {
            float learning_rate = 0.0f;

            std::cout << "Enter learning rate for this network: ";
            std::cin >> learning_rate;

            return learning_rate;
        }


    int enter_batch_size()
        {
            int batch_size = 0;

            std::cout << "Enter batch size for this network: ";
            std::cin >> batch_size;

            return batch_size;
        }


    bool ask_to_save_network_configuration(const NetworkConfig& config)
        {
            std::string choice = "";
            config.outputNetworkConfigData(std::cout);
            std::cout << "\nSave this configuration? (y/n): ";
            std::cin >> choice;

            if ((choice == "Y") || (choice == "y"))
                return 1;

            return 0;
        }

    std::string enter_output_data_file_path()
        {
            std::string output_file_path = "";

            std::cout << "Enter save file path to save config: ";
            std::cin >> output_file_path;

            std::ofstream output_file;
            output_file.open((output_file_path));

                if (!output_file.is_open())
                    {
                        output_file.close();
                        return output_file_path;
                    }

                else 
                    {
                        output_file.close();
                        std::cout << "\n[ERROR][Could not open output file]\n";
                        return "";
                    }
        }

    bool networked_created(NetworkConfig& config)
        {

        while (true)
                {
                    bool save = createNewNetwork::ask_to_save_network_configuration(config);

                    //if network is saved, it will return a date created variable
                    if (save) 
                        {   
                            config.save_file_path = Menu::createNewNetwork::enter_output_data_file_path();
                            if (config.save_config())
                                {
                                    config.save_current_date();
                                    return 1;
                                }
                            else
                                {
                                    std::string choice = "";
                                    std::cout << "Data failed to save, try to save again? (y/n): ";
                                    std::cin >> choice;

                                    if (choice == "Y" || choice != "y")
                                        continue;
                                }
                        }
        
                    else 
                        return 0;
            
                    }

        }





    //createNewNetwork namespace
    }

//Menu namespace
}
