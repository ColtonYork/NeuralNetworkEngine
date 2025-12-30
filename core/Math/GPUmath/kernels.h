#include <cuda_runtime.h>

namespace Kernel {
    
__global__ void addArray(float* arr, int add, size_t n);

}
