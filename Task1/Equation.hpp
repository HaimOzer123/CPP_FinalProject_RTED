#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <cstddef>

class Equation {
private:
    double a_;  // Coefficient a, must be non-zero
    double b_;  // Coefficient b
    double c_;  // Coefficient c
    double* solutions_; // Array of solutions (dynamic memory)
    std::size_t solutions_size_;    // Number of solutions (size of the array[0, 1, 2])

    void update_solutions();

public:
    Equation(double a, double b, double c);
};

#endif