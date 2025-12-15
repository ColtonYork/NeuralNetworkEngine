#include <vector>
#include <string>
#include <fstream>
#include <iostream>


namespace DataHandler 
{   
    std::vector<float> retrieve_input_vector(const std::string& input_data_file_path, size_t input_size);

    /*
        Brief: returns a vector of saved configs from the userData.txt file
    */
    std::vector<std::string> load_user_network_names();

    /*
        Brief: Adds a netwrok to the userData.txt file
    */
    void add_new_network_name(const std::string& name);

    
};