#include "Equation.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <memory>
#include <stdexcept>

/**
 * @brief Constructs an Equation with coefficients pa, pb, and pc.
 * @param pa Coefficient A (must not be zero)
 * @param pb Coefficient B
 * @param pc Coefficient C
 * @throw std::invalid_argument if pa is zero
 */
Equation::Equation(double pa, double pb, double pc)
    : pa(pa), pb(pb), pc(pc), solutions(nullptr), solutions_size(0) {
    if (pa == 0) throw std::invalid_argument("Coefficient pa cannot be zero.");
    update_solutions();
}

/**
 * @brief Destructor: Automatically releases resources handled by unique_ptr.
 */
Equation::~Equation() = default;

/**
 * @brief Copy constructor: Creates a new Equation by copying coefficients and solutions.
 * @param other Another Equation object to copy from.
 */
Equation::Equation(const Equation& other)
    : pa(other.pa), pb(other.pb), pc(other.pc), solutions_size(other.solutions_size) {
    solutions = std::make_unique<double[]>(solutions_size);
    for (std::size_t i = 0; i < solutions_size; ++i) {
        solutions[i] = other.solutions[i];
    }
}

/**
 * @brief Copy assignment operator: Deep-copies coefficients and solutions from another Equation.
 * @param other Another Equation object to copy from.
 * @return Reference to the updated Equation.
 */
Equation& Equation::operator=(const Equation& other) {
    if (this == &other) return *this; // Handle self-assignment
    solutions.reset(); // Release old memory
    pa = other.pa;
    pb = other.pb;
    pc = other.pc;
    solutions_size = other.solutions_size;
    solutions = std::make_unique<double[]>(solutions_size);
    for (std::size_t i = 0; i < solutions_size; ++i) {
        solutions[i] = other.solutions[i];
    }
    return *this;
}

/**
 * @brief Move constructor: Transfers ownership of resources from another Equation.
 * @param other Another Equation object to move from.
 */
Equation::Equation(Equation&& other) noexcept
    : pa(other.pa), pb(other.pb), pc(other.pc), solutions(std::move(other.solutions)), solutions_size(other.solutions_size) {
    other.solutions_size = 0;
}

/**
 * @brief Move assignment operator: Transfers resources from another Equation, releasing current resources.
 * @param other Another Equation object to move from.
 * @return Reference to the updated Equation.
 */
Equation& Equation::operator=(Equation&& other) noexcept {
    if (this != &other) {
        solutions.reset(); // Release current resources
        pa = other.pa;
        pb = other.pb;
        pc = other.pc;
        solutions = std::move(other.solutions);
        solutions_size = other.solutions_size;
        other.solutions_size = 0;
    }
    return *this;
}

/**
 * @brief Updates the solutions array based on the values of pa, pb, and pc.
 */
void Equation::update_solutions() {
    solutions.reset(); // Clears previous memory
    double discriminant = pb * pb - 4 * pa * pc;

    if (discriminant > 0) {
        solutions_size = 2;
        solutions = std::make_unique<double[]>(2); // Allocate memory for two solutions
        solutions[0] = (-pb + std::sqrt(discriminant)) / (2 * pa);
        solutions[1] = (-pb - std::sqrt(discriminant)) / (2 * pa);
    } else if (discriminant == 0) {
        solutions_size = 1;
        solutions = std::make_unique<double[]>(1); // Allocate memory for one solution
        solutions[0] = -pb / (2 * pa);
    } else {
        solutions_size = 0;
    }
}

/**
 * @brief Overloaded << operator to display the equation in the format "pa X^2 + pb X + pc = 0".
 * @param os Output stream.
 * @param eq The Equation object to display.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Equation& eq) {
    os << std::fixed << std::setprecision(1)
       << eq.pa << " X^2 + " << eq.pb << " X + " << eq.pc << " = 0";
    return os;
}

/**
 * @brief Overloaded + operator to add two Equation objects, ensuring pa remains non-zero.
 * @param lhs Left Equation object.
 * @param rhs Right Equation object.
 * @return New Equation object with summed coefficients.
 * @throw std::invalid_argument if the resulting pa is zero.
 */
Equation operator+(const Equation& lhs, const Equation& rhs) {
    if (lhs.pa + rhs.pa == 0) throw std::invalid_argument("Resultant coefficient pa cannot be zero.");
    return Equation(lhs.pa + rhs.pa, lhs.pb + rhs.pb, lhs.pc + rhs.pc);
}

/**
 * @brief Overloaded + operator to add a double to an Equation's pc coefficient.
 * @param eq Equation object.
 * @param value Value to add to pc.
 * @return New Equation object with modified pc.
 */
Equation operator+(const Equation& eq, double value) {
    return Equation(eq.pa, eq.pb, eq.pc + value);
}

/**
 * @brief Overloaded + operator to add an Equation to a double.
 * @param value Value to add to pc.
 * @param eq Equation object.
 * @return New Equation object with modified pc.
 */
Equation operator+(double value, const Equation& eq) {
    return eq + value;
}

/**
 * @brief Returns the number of solutions (0, 1, or 2).
 * @return Size of the solutions array.
 */
std::size_t Equation::get_solutions_size() const {
    return solutions_size;
}

/**
 * @brief Returns a pointer to the solutions array.
 * @return A constant pointer to the solutions array.
 */
const double* Equation::get_solutions() const {
    return solutions.get(); // Return the raw pointer managed by unique_ptr
}
