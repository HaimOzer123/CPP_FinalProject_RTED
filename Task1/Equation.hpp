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
    Equation(double a, double b, double c); // Constructor

    Equation(const Equation& other); // Copy constructor
    Equation& operator=(const Equation& other); // Copy assignment operator
    ~Equation(); // Destructor
    Equation(Equation&& other) noexcept; // Move constructor
    Equation& operator=(Equation&& other) noexcept; // Move assignment operator

    double get_a() const;
    double get_b() const;
    double get_c() const; 
    void set_a(double a);
    void set_b(double b);
    void set_c(double c); 
    std::size_t get_solutions_size() const; 
    const double* get_solutions() const; // Returns a pointer to the solutions array

    friend std::ostream& operator<<(std::ostream& os, const Equation& eq); // Output operator
    friend Equation operator+(const Equation& lhs, const Equation& rhs); 
    friend Equation operator+(const Equation& eq, double value); 
    friend Equation operator+(double value, const Equation& eq); 
};

#endif