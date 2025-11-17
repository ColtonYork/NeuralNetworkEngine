#include <string>
#include "enums/enums.h"
namespace Menu
{

    /*
        brief Start Menu of the entire netowrk. Gives the user multiple opttions and returns teh users chocie
        Input: none
        Output: 
            Int: User's choice
    */
   int startMenu();


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




    }
}