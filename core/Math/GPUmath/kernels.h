#include <cstddef>
#include <cstdint>
#include <cuda_runtime.h>

namespace Kernel {
    
__global__ void addArray(float* arr, int add, size_t n);

__global__ void matMul(float* arr1, float* arr2, float* output, size_t arr1Size, size_t arr2Size, size_t outputSize);

}
