#include "UI/Menu.h"
#include "Network/NeuralNetwork/NetworkConfig.h"
#include <iostream>


int main(const int argc, const char *argv[])
{

    int choice1 = Menu::startMenu();

    //user selects 'create new network'
    if (choice1 == 1)
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
            
            network_config.input_data_file_path = Menu::createNewNetwork::enter_input_data_file_path();
        }
}