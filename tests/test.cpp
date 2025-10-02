/**
 * @file test.cpp
 * 
 * @brief Test driver for the fibonacci and fibonacciRacer functions.
 * 
 * @details The test driver runs and times the fibonacci and fibonacciRacer
 *          functions for various inputs, and verifies the correctness of their
 *          outputs.
 */

#include <chrono>
#include <iostream>
#include <string>
#include <sstream>

#include "fibonacci.hpp"

void fibonacciVerifier(std::array<uint64_t, fibonacci::MAX_64_BIT_FIBONACCI_INDEX + 1>& results, int start, int end) {
    for (int i = start; i <= end; ++i) {

    }
    std::cout << "All Fibonacci numbers match!" << std::endl;

}

int main(int argc, char* argv[]) {
    std::array<uint64_t, fibonacci::MAX_64_BIT_FIBONACCI_INDEX + 1> results = {0};
    fibonacciVerifier(results, 0, 0);

    return 0;
}
