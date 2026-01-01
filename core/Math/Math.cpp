#include "Math.h"
#include "GPUmath/GPUmath.h"

namespace Math {
void addArray(std::vector<float>& arr, int add, bool useGPU)
{
    if (useGPU)
        GPU::addArray(arr.data(), add, arr.size());
}


  void matMul(std::vector<float>& matrix1, std::vector<float>& matrix2, std::vector<float>& outputVec, bool useGPU)
{
  if (useGPU)
    GPU::matMul(matrix1.data(), matrix2.data(), outputVec.data(), matrix1.size());

}
}
