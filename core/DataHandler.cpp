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
            size_t i = 0;
            while (i < input_size && input_data_file >> return_vector[i])
                {i++;}

            input_data_file.close();
            
            return return_vector;
            
        }

    std::vector<std::string> load_user_network_names()
        {
            std::ifstream stream;
            stream.open("UserData/userData.txt");

            std::vector<std::string> names;
            std::string temp_name;

            while (stream >> temp_name) 
                names.push_back(temp_name);

            return names;
        }



    void add_new_network_name(const std::string& name)
        {
            std::vector<std::string> names = load_user_network_names();

            names.push_back(name);

            std::ofstream stream;
            stream.open("UserData/userData.txt");

            for (int i = 0; i < names.size(); i++)
                {
                    stream << names[i] << '\n';
                }
        }

};