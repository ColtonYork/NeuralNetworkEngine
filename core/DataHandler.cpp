#include "DataHandler.h"


namespace DataHandler 
{
    std::vector<float> retrieve_input_vector(const std::string &input_data_file_path, size_t input_size)
        {
            std::vector<float> return_vector(0);
            std::ifstream input_data_file;

            input_data_file.open(input_data_file_path);

            if (!input_data_file.is_open())
                {
                    std::cout << "[ERROR][Could not open input data file given]\n";
                    return return_vector;
                    
                }

            return_vector.resize(input_size);

            //load data into vector
            int i = 0;
            while (i < input_size && input_data_file >> return_vector[i])
                {i++;}

            input_data_file.close();
            
            return return_vector;
            
        }
};