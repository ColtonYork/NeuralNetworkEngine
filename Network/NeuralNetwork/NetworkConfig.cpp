# include "NetworkConfig.h"


void NetworkConfig::outputNetworkConfigData() const
{
    std::cout << "  " <<
    UIutils::to_upper(network_name) << " CONFIGURATION DATA        \n"
    "--------------------------------\n";
    std::cout << "//NETWORK DETAILS//\n";
    std::cout << "Network Name: " << network_name << '\n';
    std::cout << "Date Created: " << date_created << '\n';

    std::cout << '\n';
    std::cout << "//ARCHITECTURE//\n";
    std::cout << "Number of Layers: " << layers << '\n';
    
    std::cout << '\n';
    std::cout << "//TRAINING//\n";
    std::cout << "Epochs trained: " << epochs << '\n';
    std::cout << "Loss of last epoch: " << loss << '\n';
    std::cout << "Learning rate: " << learning_rate << '\n';
    std::cout << "Batch size: " << batch_size << '\n';
    
    std::cout << '\n';
}

void LayerConfig::outputLayerConfigData(const int& layerNum) const
{
    std::cout << "                  ---------------------------------------------------------------------------------------------------\n";
    std::cout << "                  | Layer " << layerNum << " size: " << layerSize;
    std::cout << std::setw(80) << std::right << "|\n";
    std::cout << " Layer " << layerNum << "          | Layer " << layerNum << " layer type: " << UIutils::LayerTypeToString(layer_type);
    std::cout << std::setw(80) << std::right << "|\n";
    std::cout << "                  | Layer " << layerNum << " activation function: " << UIutils::ActivationFunctionToString(activation_function);
    std::cout << std::setw(80) << std::right << "|\n";
}


void NetworkConfig::outputAllLayerConfigs() const
{
    for(size_t i = 0; i < layerData.size(); i++)
        {
            layerData[i].outputLayerConfigData(i);
        }
}

