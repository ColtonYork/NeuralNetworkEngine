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


void matMul(float* A, float* B, float* C, size_t N)
{
  float* gpu_A;
  float* gpu_B;
  float* gpu_C;

  //allocate memory on gpu
  cudaMalloc(&gpu_A, N * N * sizeof(float));
  cudaMalloc(&gpu_B, N * N * sizeof(float));
  cudaMalloc(&gpu_C, N * N * sizeof(float));

  //copy memory to gpu
  cudaMemcpy(gpu_A, A, N * N * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_B, B, N * N * sizeof(float), cudaMemcpyHostToDevice);

  dim3 threadsPerBlock(TILE, TILE);
  dim3 numBlocks((N + TILE - 1)/TILE, (N + TILE - 1)/TILE);

  Kernel::matMul<<<numBlocks, threadsPerBlock>>>(gpu_A, gpu_B, gpu_C, N);  cudaDeviceSynchronize();

  cudaMemcpy(C, gpu_C, N * N * sizeof(float), cudaMemcpyDeviceToHost);
  cudaFree(gpu_A);
  cudaFree(gpu_B);
  cudaFree(gpu_C);
}
}



