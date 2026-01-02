#include <vector>
#include <cstddef>
namespace Math 
{


  void addArray(std::vector<float>& arr, int add, bool useGPU);


void matMul(std::vector<float>& matrix1, std::vector<float>& matrix2, 
            std::vector<float>& outputVec, 
            size_t M, size_t K, size_t N, bool useGPU);
}

