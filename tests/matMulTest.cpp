#include "../UI/Menu.h"
#include "../core/Math/Math.h"
#include "../App.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Your Math namespace (assuming this is included)
// namespace Math { ... }

// Helper function to print results
void printMatrix(const std::vector<float>& mat, size_t rows, size_t cols, const std::string& name) {
    std::cout << name << " (" << rows << "x" << cols << "):\n";
    for (size_t i = 0; i < rows; i++) {
        std::cout << "  ";
        for (size_t j = 0; j < cols; j++) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) 
                      << mat[i * cols + j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Helper function to compare results
bool compareVectors(const std::vector<float>& result, const std::vector<float>& expected, 
                    float epsilon = 0.001f) {
    if (result.size() != expected.size()) return false;
    for (size_t i = 0; i < result.size(); i++) {
        if (std::abs(result[i] - expected[i]) > epsilon) {
            std::cout << "  Mismatch at index " << i << ": got " << result[i] 
                      << ", expected " << expected[i] << "\n";
            return false;
        }
    }
    return true;
}

// Test function
void runTest(const std::string& testName,
             std::vector<float>& A, size_t M, size_t K,
             std::vector<float>& B, size_t K2, size_t N,
             const std::vector<float>& expected) {
    
    std::cout << "========================================\n";
    std::cout << "Test: " << testName << "\n";
    std::cout << "========================================\n";
    
    std::vector<float> C(M * N, 0.0f);
    
    printMatrix(A, M, K, "Matrix A");
    printMatrix(B, K2, N, "Matrix B");
    
    // Run GPU matMul
    Math::matMul(A, B, C, M, K, N, true);
    
    printMatrix(C, M, N, "Result C");
    printMatrix(expected, M, N, "Expected");
    
    if (compareVectors(C, expected)) {
        std::cout << "✓ PASSED\n\n";
    } else {
        std::cout << "✗ FAILED\n\n";
    }
}

int main() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "║   CUDA Matrix Multiplication Tests    ║\n";
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "\n";

    // ========================================
    // Test 1: Basic 1x2 × 2x3 (Your original test)
    // ========================================
    {
        std::vector<float> A = {1, 2};
        std::vector<float> B = {1, 2, 3, 4, 5, 6};
        std::vector<float> expected = {9, 12, 15};
        runTest("1x2 × 2x3 (Neural Network Layer)", A, 1, 2, B, 2, 3, expected);
    }

    // ========================================
    // Test 2: Square 2x2 × 2x2
    // ========================================
    {
        std::vector<float> A = {1, 2,
                                3, 4};
        std::vector<float> B = {5, 6,
                                7, 8};
        std::vector<float> expected = {19, 22,
                                       43, 50};
        runTest("2x2 × 2x2 (Square Matrices)", A, 2, 2, B, 2, 2, expected);
    }

    // ========================================
    // Test 3: 3x2 × 2x4 (Rectangular)
    // ========================================
    {
        std::vector<float> A = {1, 2,
                                3, 4,
                                5, 6};
        std::vector<float> B = {1, 2, 3, 4,
                                5, 6, 7, 8};
        std::vector<float> expected = {11, 14, 17, 20,
                                       23, 30, 37, 44,
                                       35, 46, 57, 68};
        runTest("3x2 × 2x4 (Rectangular)", A, 3, 2, B, 2, 4, expected);
    }

    // ========================================
    // Test 4: Identity Matrix
    // ========================================
    {
        std::vector<float> A = {1, 2, 3};
        std::vector<float> I = {1, 0, 0,
                                0, 1, 0,
                                0, 0, 1};
        std::vector<float> expected = {1, 2, 3};
        runTest("1x3 × 3x3 Identity (Should preserve A)", A, 1, 3, I, 3, 3, expected);
    }

    // ========================================
    // Test 5: Zeros
    // ========================================
    {
        std::vector<float> A = {0, 0};
        std::vector<float> B = {1, 2, 3,
                                4, 5, 6};
        std::vector<float> expected = {0, 0, 0};
        runTest("1x2 × 2x3 with Zero Matrix", A, 1, 2, B, 2, 3, expected);
    }

    // ========================================
    // Test 6: Single element
    // ========================================
    {
        std::vector<float> A = {5};
        std::vector<float> B = {3};
        std::vector<float> expected = {15};
        runTest("1x1 × 1x1 (Scalar)", A, 1, 1, B, 1, 1, expected);
    }

    // ========================================
    // Test 7: Larger matrix (4x4 × 4x4)
    // ========================================
    {
        std::vector<float> A = {1,  2,  3,  4,
                                5,  6,  7,  8,
                                9,  10, 11, 12,
                                13, 14, 15, 16};
        std::vector<float> B = {1, 0, 0, 0,
                                0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1};
        std::vector<float> expected = A;  // Identity should preserve A
        runTest("4x4 × 4x4 Identity", A, 4, 4, B, 4, 4, expected);
    }

    // ========================================
    // Test 8: Neural network batch example (2x3 × 3x2)
    // ========================================
    {
        std::vector<float> A = {1, 2, 3,
                                4, 5, 6};  // 2 samples, 3 features
        std::vector<float> B = {1, 2,
                                3, 4,
                                5, 6};     // 3 input features, 2 output features
        std::vector<float> expected = {22, 28,
                                       49, 64};
        runTest("2x3 × 3x2 (Batch Processing)", A, 2, 3, B, 3, 2, expected);
    }

    std::cout << "========================================\n";
    std::cout << "All tests completed!\n";
    std::cout << "========================================\n\n";

    return 0;
}
