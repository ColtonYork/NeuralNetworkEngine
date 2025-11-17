#include <string>
#include <vector>
#include "../enums/enums.h"



struct LayerConfig
{
    int layerSize = 0;
    ActivationFunction activation_function = ActivationFunction::None;
    LayerType layer_type = LayerType::None;
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
};