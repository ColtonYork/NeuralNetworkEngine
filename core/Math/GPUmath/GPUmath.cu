//Wrappers for CUDA kernels
#include "GPUmath.h"
#include "kernels.h"
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

constexpr int DEFAULT_THREADS_PER_BLOCK = 256;
namespace GPU {
void addArray(float* arr, int add, size_t arrSize)
{
    float* gpu_arr;
    cudaMalloc(&gpu_arr, arrSize * sizeof(float));
    cudaMemcpy(gpu_arr, arr, arrSize * sizeof(float), cudaMemcpyHostToDevice);

    int numBlocks = (arrSize + DEFAULT_THREADS_PER_BLOCK - 1) / DEFAULT_THREADS_PER_BLOCK;
    Kernel::addArray<<<numBlocks, DEFAULT_THREADS_PER_BLOCK>>>(gpu_arr, add, arrSize);

    cudaDeviceSynchronize();

    cudaMemcpy(arr, gpu_arr, arrSize * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(gpu_arr);
}    
}

