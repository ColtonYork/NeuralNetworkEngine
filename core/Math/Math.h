#include <vector>
namespace Math 
{


  void addArray(std::vector<float>& arr, int add, bool useGPU);

  void matMul(std::vector<float>& matrix1, std::vector<float>& matrix2, std::vector<float>& outputVec, bool useGPU);
}

