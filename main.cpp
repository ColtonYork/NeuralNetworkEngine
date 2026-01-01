#include "UI/Menu.h"
#include "core/Math/Math.h"
#include "App.h"
#include <iostream>
#include <vector>

int main(const int argc, const char *argv[])
{
    // App app;
    // app.run();
            
    // return 0;
  
// ---- Input layer: 1x2 vector ----
    std::vector<float> A = {1, 2}; // 1 row, 2 columns

    // ---- Weight matrix: 2x3 (2 inputs -> 3 outputs) ----
    // Flattened row-major order: row0 | row1
    std::vector<float> B = {
        1, 2, 3,  // row 0
        4, 5, 6   // row 1
    };

    // ---- Output vector: 1x3 ----
    std::vector<float> C(3, 0.0f);

    // ---- Call GPU matMul ----
    Math::matMul(A, B, C, true);

    // ---- Print output ----
    std::cout << "Output vector C: ";
    for (float val : C) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // ---- Expected output ----
    // Compute by hand:
    // C[0] = 1*1 + 2*4 = 1 + 8 = 9
    // C[1] = 1*2 + 2*5 = 2 + 10 = 12
    // C[2] = 1*3 + 2*6 = 3 + 12 = 15
    std::cout << "Expected: 9 12 15" << std::endl;

    return 0;
  

}
