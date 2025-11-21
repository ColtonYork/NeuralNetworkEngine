#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include "../../core/enums/enums.h"
#include "../../UI/UIutils.h"



struct LayerConfig
{
    int layerSize = 0;
    LayerType layer_type = LayerType::None;
    ActivationFunction activation_function = ActivationFunction::None;

    void outputLayerConfigData(const int& layerNum, std::ostream& stream) const;

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

    //data
    int epochs_trained = 0;
    float loss = 0.0f;

    //training data
    std::string input_data_file_path = "";

    //save file
    std::string save_file_path = "";

    void outputNetworkConfigData(std::ostream& stream) const;

    void outputAllLayerConfigs(std::ostream& stream) const;

    void save_current_date();

    /*
    Brief: Saves the users configuration into a file they choose
    Input:
        string file path to desired output file location
    Output:
        file succesfully saved or not
    */
    bool save_config(const std::string& output_file_path) const;

    
    /*
        Brief: returns to save_file_path member
        Input: none
        Output:
            bool succesfulness of save
    */
    bool save_config() const;

    void reset_date_created();


};