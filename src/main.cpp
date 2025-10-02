#include <chrono>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>

#include "fibonacci.hpp"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "An integer argument is required to run this program!\n"
                  << "Example: \"" << argv[0] << " 100\"\n";
        return 1;
    }

    int n;
    try {
        n = std::stoi(argv[1]);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Error: Invalid argument. Not a number: " << argv[1] << "\n";
        return 1;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Error: Argument out of range: " << argv[1] << "\n";
        return 1;
    }

    if (n < 0 || n > fibonacci::MAX_64_BIT_FIBONACCI_INDEX) {
        std::cerr << "Error: Argument must be between 0 and " << fibonacci::MAX_64_BIT_FIBONACCI_INDEX << ".\n";
        return 1;
    }

    const auto start = std::chrono::high_resolution_clock::now();
    // Store result in a volatile variable to strongly suggest no compiler optimizations
    volatile uint64_t result = fibonacci::fibonacci(n);
    const auto end = std::chrono::high_resolution_clock::now();
    const auto durationMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "The " << n << "th Fibonacci number is " << result << '\n';
    std::cout << "Program execution time: " << durationMicroseconds.count() << " Microseconds" << "\n";

    return 0;
}