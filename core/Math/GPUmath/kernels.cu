#include "kernels.h"
#include <stdio.h>
#define TILE 16

namespace Kernel {
__global__ void addArray(float* arr, int add, size_t n){
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx < n)
    arr[idx] += add;

    //printf("Thread %d added %d to index %d, new value: %f\n", idx, add, idx, arr[idx]);

}


__global__ void matMul(float* A, float* B, float* C, size_t N) {
  __shared__ float As[TILE][TILE];
  __shared__ float Bs[TILE][TILE];

  int row = blockIdx.y * TILE + threadIdx.y;
  int col = blockIdx.x * TILE + threadIdx.x;

  float sum = 0.0f;

  for (int t = 0; t < (N + TILE - 1) / TILE; t++) {

    int a_col = t * TILE + threadIdx.x;
    int b_row = t * TILE + threadIdx.y;

    // Load tiles into shared memory
    As[threadIdx.y][threadIdx.x] =
        (row < N && a_col < N) ? A[row * N + a_col] : 0.0f;

    Bs[threadIdx.y][threadIdx.x] =
        (b_row < N && col < N) ? B[b_row * N + col] : 0.0f;

    __syncthreads();

    // Compute using fast shared memory
    for (int k = 0; k < TILE; k++) {
      sum += As[threadIdx.y][k] * Bs[k][threadIdx.x];
    }

    __syncthreads();
  }

  if (row < N && col < N) {
    C[row * N + col] = sum;
  }
}
}