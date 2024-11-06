#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <stdexcept>
#include <cstddef>
#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * @brief Represents a Quadratic Equation of the form A * X^2 + B * X + C = 0
 */
class Equation {
private:
    double pa; /**< Coefficient A, should never be zero */
    double pb; /**< Coefficient B */
    double pc; /**< Coefficient C */
    double* solutions; /**< Pointer to array holding the solutions */
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
    /**
     * @brief Returns the value of coefficient pa.
     * @return The value of pa.
     */
    double get_pa() const;

    /**
     * @brief Returns the value of coefficient pb.
     * @return The value of pb.
     */
    double get_pb() const;

    /**
     * @brief Returns the value of coefficient pc.
     * @return The value of pc.
     */
    double get_pc() const;

    /**
     * @brief Sets the value of coefficient pa.
     * @param pa New value for coefficient A.
     * @throw std::invalid_argument if pa is set to zero.
     */
    void set_pa(double pa);

    /**
     * @brief Sets the value of coefficient pb.
     * @param pb New value for coefficient B.
     */
    void set_pb(double pb);

    /**
     * @brief Sets the value of coefficient pc.
     * @param pc New value for coefficient C.
     */
    void set_pc(double pc);

    /**
     * @brief Returns the size of the solutions array.
     * @return The number of solutions (0, 1, or 2).
     */
    std::size_t get_solutions_size() const;

    /**
     * @brief Returns a pointer to the solutions array.
     * @return A constant pointer to the solutions array.
     */
    const double* get_solutions() const;

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Equation& eq);
    friend Equation operator+(const Equation& lhs, const Equation& rhs);
    friend Equation operator+(const Equation& eq, double value);
    friend Equation operator+(double value, const Equation& eq);
};

#endif
