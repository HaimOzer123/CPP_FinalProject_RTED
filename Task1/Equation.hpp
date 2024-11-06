#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <stdexcept>
#include <cstddef>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory> // Include for std::unique_ptr

/**
 * @class Equation
 * @brief Represents a quadratic equation of the form A * X^2 + B * X + C = 0.
 * 
 * This class provides methods to manage quadratic equations, including solving
 * for real roots, operator overloading for equation addition, and safe memory 
 * management using unique pointers. It follows the Rule of Three and Rule of 
 * Five to handle deep copying and resource ownership transfer efficiently.
 * 
 * Key constraints:
 * - `a` (coefficient of X^2) must be non-zero; attempts to set `a` to zero 
 *   will throw an exception.
 * - Solutions are calculated dynamically when coefficients are modified.
 */

class Equation {
private:
    double pa; /**< Coefficient A, should never be zero */
    double pb; /**< Coefficient B */
    double pc; /**< Coefficient C */
    std::unique_ptr<double[]> solutions; /**< Smart pointer to array holding the solutions */
    std::size_t solutions_size; /**< Number of solutions (0, 1, or 2) */

    /**
     * @brief Updates the solutions array based on the values of pa, pb, and pc.
     */
    void update_solutions();

public:
    /**
     * @brief Constructs an Equation with coefficients pa, pb, and pc.
     * @param pa Coefficient A (must not be zero)
     * @param pb Coefficient B
     * @param pc Coefficient C
     * @throw std::invalid_argument if pa is zero
     */
    Equation(double pa, double pb, double pc);

    // Rule of Three and Rule of Five
    Equation(const Equation& other);
    Equation& operator=(const Equation& other);
    ~Equation();
    Equation(Equation&& other) noexcept;
    Equation& operator=(Equation&& other) noexcept;

    // Accessor methods
    double get_pa() const;
    double get_pb() const;
    double get_pc() const;
    void set_pa(double pa);
    void set_pb(double pb);
    void set_pc(double pc);
    std::size_t get_solutions_size() const;
    const double* get_solutions() const;

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Equation& eq);
    friend Equation operator+(const Equation& lhs, const Equation& rhs);
    friend Equation operator+(const Equation& eq, double value);
    friend Equation operator+(double value, const Equation& eq);
};

#endif
