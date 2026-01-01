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
    
    /*
        Brief: Multiplies 2 matricies and returns the matrix in the third parameter
        Input:
          A: matrix 1
          B: matrix 2
          C: output matrix
          N: Array size
        Output:
          Stored in array C
    */
    void matMul(float* A, float* B, float* C, size_t N);              
}
