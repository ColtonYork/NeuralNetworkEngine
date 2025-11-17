#include <string>
#include <vector>
#include <iostream>
#include "../enums/enums.h"
#include "UI/UIutils.h"



struct LayerConfig
{
    int layerSize = 0;
    LayerType layer_type = LayerType::None;
    ActivationFunction activation_function = ActivationFunction::None;

};



struct NetworkConfig
{
    //Netowrk//
    std::string network_name = "";
    std::string date_created = "";

    //Architecture//
    int layers = 0;
    std::vector<LayerConfig> layerData;

    //Training//
    int batch_size = 0;
    float learning_rate = 0.0f;

    void outputNetworkConfigData() const;
};