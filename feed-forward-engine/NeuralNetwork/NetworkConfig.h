#include <string>
#include <vector>



struct LayerConfig
{
    int layerSize = 0;
    std::string activation = "";
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