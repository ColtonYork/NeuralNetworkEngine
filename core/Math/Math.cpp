#include "Math.h"
#include "GPUmath/GPUmath.h"

namespace Math {
void addArray(std::vector<float>& arr, int add, bool useGPU)
{
    if (useGPU)
        GPU::addArray(arr.data(), add, arr.size());
}
}

