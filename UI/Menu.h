#include <string>
#include "../core/enums/enums.h"
#include "../Network/NeuralNetwork/NetworkConfig.h"
#include "../core/DataHandler.h"

namespace Menu
{

    /*
        brief Start Menu of the entire netowrk. Gives the user multiple opttions and returns teh users chocie
        Input: none
        Output: 
            Int: User's choice
    */
   int startMenu();


   /*
        Brief: The serires of UI displays when user selects 'create new network' from start menu
        Input: none
        Output: irrelevant i think
   */
    bool create_new_network_selected();


    /*
        Brief: The serires of UI displays when user selects 'train a network' from start menu
        Input: none
        Output: irrelevant i think
   */
    bool train_a_network_selected();

    namespace trainANetwork
    {

        /*
            Brief: Asks user to select their network and returns it as a string
            Input: none
            Output: 
                string of users' netowrk name

        */
        std::string ask_user_to_select_their_netowrk();   

        /*
            Brief: displays the name of all of the users' saved networks
            Inpout: None
            Output: None
        */
        void display_users_saved_netowrks();
    }

    namespace createNewNetwork
    {
        /*
            brief: Asks the user to name the netowrk and returns it as a string
            input: none
            output: 
                string: name of network
        */
        std::string nameNetwork();


        /*
            Brief: Asks the user how many layers they want their network to be and returns the number
            Input: none
            Output:
                Int: User's choice of number of layers for the netowrk
        */
        int enterNumOfLayers();

        
        /*
            Brief: Asks the user how many layers they want their network to be and returns the number
            Input: none
            Output:
                Int: User's choice for size of input layer
        */
        int enterInputLayerSize();


        /*
            Brief: Asks the user to input the size for a specified layer
            Input: 
                LayerNum: The layer number that the question will display for
            Output:
                Int: User's choice for size of this layer
        */
        int enterLayerSize(const int& layerNum);


        /*
            Brief: Asks the user to input the layer type for a specified layer
            Input: 
                LayerNum: The layer number that the question will display for
            Output:
                LayerType: User's choice for layer type of this layer
        */
        LayerType enterLayerType(const int& layerNum);

        /*
            Brief: displays the types of layers that the user can choose from
            Input: none
            Output: none
        */
        void displayLayerTypes();


        /*
            Brief: displays the types of activation functions the user can choose from
            Input: none
            output: none
        */
        void displayActivationTypes();

        /*
            Brief: Asks the user to input the activation function type for a specified layer
            Input: 
                LayerNum: The layer number that the question will display for
            Output:
                ActivationFunction: User's choice for the activation function for a specified layer layer
        */
        ActivationFunction enterActivationFunction(const int& layerNum);

        /*
            Brief: Asks the user to input the path to their input data file
            Input: none
            Output:
                std::string path to input data file
        */
        std::string enter_input_data_file_path();

        /*
            Brief: Asks the user to input the path to their outpus/save data file
            Input: none
            Output:
                std::string path to save data file
        */
        std::string enter_output_data_file_path();

        /*
            Brief: outputs an example file to the terminal to show user the intended input data file format
            Input: none
            Output: none
        */
        void output_input_data_file_format();

        /*
            Brief: Asks the user to set a batch size for the network configuration
            Input: none
            Output:
                int batch size for config
        */
        int enter_batch_size();
        

        /*
            Brief: Asks the user to set a learning rate for the network configuration
            Input: none
            Output:
                Float learning rate for config
        */
        float enter_learning_rate();

        /*
            Brief: Outputs the network config data and asks user if they want to save it.
            input: 
                config: The cofiguration that the user will ask to be asved or not
            Output:
                Boolean: 1 to save. 0 to discard
        */
        bool ask_to_save_network_configuration(const NetworkConfig& config);

        /*
            Brief: returns true if a netwrok was saved after user selects 'create new netwrok configuration' from menu
            Input: 
                none
            Output: if a network was created/saves 
        */
        bool networked_created(NetworkConfig& config);





    }
}