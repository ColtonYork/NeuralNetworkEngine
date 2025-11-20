#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "../../core/enums/enums.h"
#include "../../UI/UIutils.h"



struct LayerConfig
{
    int layerSize = 0;
    LayerType layer_type = LayerType::None;
    ActivationFunction activation_function = ActivationFunction::None;

    void outputLayerConfigData(const int& layerNum) const;

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
    int epochs = 0;
    float loss = 0.0f;

    //training data
    std::string input_data_file_path = "";

    void outputNetworkConfigData() const;

    void outputAllLayerConfigs() const;
};