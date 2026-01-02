#include "Math.h"
#include "GPUmath/GPUmath.h"

namespace Math {
void addArray(std::vector<float>& arr, int add, bool useGPU)
{
    if (useGPU)
        GPU::addArray(arr.data(), add, arr.size());
}


void matMul(std::vector<float>& matrix1, std::vector<float>& matrix2, 
            std::vector<float>& outputVec, 
            size_t M, size_t K, size_t N, bool useGPU)
{
  if (useGPU)
    GPU::matMul(matrix1.data(), matrix2.data(), outputVec.data(), M, K, N);
}
}
