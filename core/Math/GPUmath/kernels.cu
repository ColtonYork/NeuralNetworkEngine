#include "kernels.h"
#include <stdio.h>
namespace Kernel {
__global__ void addArray(float* arr, int add, size_t n){
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n)
        arr[idx] += add;

    //printf("Thread %d added %d to index %d, new value: %f\n", idx, add, idx, arr[idx]);

}
}
