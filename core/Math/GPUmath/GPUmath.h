//kernel wrapper header file
#include <vector>
#include <cstddef>


namespace GPU 
{
    /*
        Brief: adds an integer to every element in an array
        Input:
            arr: The array being processed
            add: The number to add to each element
            arrSize: The size of the array
        Output: None
    */
    void addArray(float* arr, int add, size_t arrSize);
}
