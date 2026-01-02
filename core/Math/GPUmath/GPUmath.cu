//Wrappers for CUDA kernels
#include "GPUmath.h"
#include "kernels.h"
#include <cstring>
#include <cuda_device_runtime_api.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <driver_types.h>

#define TILE 16

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


void matMul(float* A, float* B, float* C, size_t M, size_t K, size_t N)
{
  float* gpu_A;
  float* gpu_B;
  float* gpu_C;
  
  // Allocate memory on GPU with correct sizes
  cudaMalloc(&gpu_A, M * K * sizeof(float));  // A is M×K
  cudaMalloc(&gpu_B, K * N * sizeof(float));  // B is K×N
  cudaMalloc(&gpu_C, M * N * sizeof(float));  // C is M×N
  
  // Copy memory to GPU with correct sizes
  cudaMemcpy(gpu_A, A, M * K * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_B, B, K * N * sizeof(float), cudaMemcpyHostToDevice);
  
  // Configure grid dimensions
  dim3 threadsPerBlock(TILE, TILE);
  dim3 numBlocks((N + TILE - 1)/TILE,   // columns of output
                 (M + TILE - 1)/TILE);  // rows of output
  
  // Launch kernel with M, K, N parameters
  Kernel::matMul<<<numBlocks, threadsPerBlock>>>(gpu_A, gpu_B, gpu_C, M, K, N);
  
  cudaDeviceSynchronize();
  
  // Copy result back with correct size
  cudaMemcpy(C, gpu_C, M * N * sizeof(float), cudaMemcpyDeviceToHost);
  
  // Free GPU memory
  cudaFree(gpu_A);
  cudaFree(gpu_B);
  cudaFree(gpu_C);
}
}


