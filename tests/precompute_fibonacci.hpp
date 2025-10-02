/**
 * @file precompute_fibonacci.hpp
 * 
 * @brief Include file for a compile-time precomputed Fibonacci sequence.
 * 
 * @details This file declares a `constexpr` array containing the first 94
 *          Fibonacci numbers, which fit within a 64-bit unsigned integer.
 *          This can be used for testing and verification purposes.
 */

#ifndef PRECOMPUTE_FIBONACCI_HPP
#define PRECOMPUTE_FIBONACCI_HPP

#include <array>
#include <cstdint>

constexpr int SOLUTION_COUNT = 94; // Number of Fibonacci numbers to precompute

constexpr std::array<uint64_t, SOLUTION_COUNT> precomputeFiconacci() {
    std::array<uint64_t, SOLUTION_COUNT> fibs = {0};
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i < SOLUTION_COUNT; ++i) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    return fibs;
}

constexpr std::array<uint64_t, SOLUTION_COUNT> FIBONACCI_SOLUTIONS = precomputeFiconacci();

#endif // PRECOMPUTE_FIBONACCI_HPP
