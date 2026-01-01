#include <cuda_runtime.h>

namespace Kernel {
    
__global__ void addArray(float* arr, int add, size_t n);

__global__ void matMul(float* arr1, float* arr2, float* output, size_t n);

}
