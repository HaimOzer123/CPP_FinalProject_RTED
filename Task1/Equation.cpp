#include "Equation.hpp"

/**
 * @brief Constructor with three parameters (pa, pb, pc) that initializes the coefficients.
 * Sets the solutions array to nullptr initially and calculates solutions if applicable.
 * @param pa Coefficient A, must not be zero.
 * @param pb Coefficient B.
 * @param pc Coefficient C.
 * @throw std::invalid_argument if pa is zero.
 */
Equation::Equation(double pa, double pb, double pc) : pa(pa), pb(pb), pc(pc), solutions(nullptr), solutions_size(0) {
    if (pa == 0) throw std::invalid_argument("Coefficient pa cannot be zero.");
    update_solutions();
}

/**
 * @brief Copy constructor: Initializes a new Equation by copying another Equation's coefficients and solutions.
 * @param other Another Equation object to copy from.
 */
Equation::Equation(const Equation& other) : pa(other.pa), pb(other.pb), pc(other.pc), solutions_size(other.solutions_size) {
    solutions = new double[solutions_size];
    for (std::size_t i = 0; i < solutions_size; ++i)
        solutions[i] = other.solutions[i];
}

/**
 * @brief Copy assignment operator: Assigns another Equation to this one by deep copying its coefficients and solutions.
 * @param other Another Equation object to copy from.
 * @return Reference to the modified Equation.
 */
Equation& Equation::operator=(const Equation& other) {
    if (this == &other) return *this; // Handle self-assignment
    delete[] solutions; // Release old memory
    pa = other.pa;
    pb = other.pb;
    pc = other.pc;
    solutions_size = other.solutions_size;
    solutions = new double[solutions_size];
    for (std::size_t i = 0; i < solutions_size; ++i)
        solutions[i] = other.solutions[i];
    return *this;
}

/**
 * @brief Destructor: Releases memory allocated for the solutions array.
 */
Equation::~Equation() {
    delete[] solutions;
}

/**
 * @brief Move constructor: Transfers ownership of another Equation's resources to this one.
 * @param other Another Equation object to move from.
 */
Equation::Equation(Equation&& other) noexcept : pa(other.pa), pb(other.pb), pc(other.pc), solutions(other.solutions), solutions_size(other.solutions_size) {
    other.solutions = nullptr; // Nullify other's pointer to prevent double delete
    other.solutions_size = 0;
}

/**
 * @brief Move assignment operator: Moves resources from another Equation to this one, releasing existing resources.
 * @param other Another Equation object to move from.
 * @return Reference to the modified Equation.
 */
Equation& Equation::operator=(Equation&& other) noexcept {
    if (this != &other) {
        delete[] solutions; // Release existing resources
        pa = other.pa;
        pb = other.pb;
        pc = other.pc;
        solutions = other.solutions;
        solutions_size = other.solutions_size;
        other.solutions = nullptr; // Nullify other's pointer
        other.solutions_size = 0;
    }
    return *this;
}

/**
 * @brief Getter for coefficient pa.
 * @return The value of coefficient pa.
 */
double Equation::get_pa() const { return pa; }

/**
 * @brief Getter for coefficient pb.
 * @return The value of coefficient pb.
 */
double Equation::get_pb() const { return pb; }

/**
 * @brief Getter for coefficient pc.
 * @return The value of coefficient pc.
 */
double Equation::get_pc() const { return pc; }

/**
 * @brief Setter for coefficient pa with a check to prevent setting pa to zero (non-quadratic equation).
 * Calls update_solutions to recalculate solutions after changing pa.
 * @param pa New value for coefficient A, must not be zero.
 * @throw std::invalid_argument if pa is zero.
 */
void Equation::set_pa(double pa) {
    if (pa == 0) throw std::invalid_argument("Coefficient pa cannot be zero.");
    this->pa = pa;
    update_solutions();
}

/**
 * @brief Setter for coefficient pb; recalculates solutions after setting pb.
 * @param pb New value for coefficient B.
 */
void Equation::set_pb(double pb) {
    this->pb = pb;
    update_solutions();
}

/**
 * @brief Setter for coefficient pc; recalculates solutions after setting pc.
 * @param pc New value for coefficient C.
 */
void Equation::set_pc(double pc) {
    this->pc = pc;
    update_solutions();
}

/**
 * @brief Returns the size of the solutions array.
 * @return The number of solutions (0, 1, or 2).
 */
std::size_t Equation::get_solutions_size() const {
    return solutions_size;
}

/**
 * @brief Returns a const pointer to the solutions array.
 * @return A constant pointer to the solutions array.
 */
const double* Equation::get_solutions() const {
    return solutions;
}

/**
 * @brief Private method to calculate and update the solutions array based on current values of pa, pb, and pc.
 * Updates the number of solutions and allocates memory accordingly.
 */
void Equation::update_solutions() {
    delete[] solutions; // Release previous solutions
    double discriminant = pb * pb - 4 * pa * pc; // Calculate discriminant
    if (discriminant > 0) {
        solutions_size = 2;
        solutions = new double[2];
        solutions[0] = (-pb + std::sqrt(discriminant)) / (2 * pa); // First root
        solutions[1] = (-pb - std::sqrt(discriminant)) / (2 * pa); // Second root
    } else if (discriminant == 0) {
        solutions_size = 1;
        solutions = new double[1];
        solutions[0] = -pb / (2 * pa); // Single root
    } else {
        solutions_size = 0; // No real roots
        solutions = nullptr;
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
 * @brief Overloaded + operator to add two Equation objects, resulting in a new Equation.
 * Adds the coefficients of both equations.
 * @param lhs Left-hand side Equation.
 * @param rhs Right-hand side Equation.
 * @return New Equation object with summed coefficients.
 */
Equation operator+(const Equation& lhs, const Equation& rhs) {
    return Equation(lhs.pa + rhs.pa, lhs.pb + rhs.pb, lhs.pc + rhs.pc);
}

/**
 * @brief Overloaded + operator to add a double to an Equation's pc coefficient, resulting in a new Equation.
 * @param eq The Equation object.
 * @param value The double value to add to pc.
 * @return New Equation object with modified pc coefficient.
 */
Equation operator+(const Equation& eq, double value) {
    return Equation(eq.pa, eq.pb, eq.pc + value);
}

/**
 * @brief Overloaded + operator to add an Equation to a double (double on the left), resulting in a new Equation.
 * @param value The double value to add to pc.
 * @param eq The Equation object.
 * @return New Equation object with modified pc coefficient.
 */
Equation operator+(double value, const Equation& eq) {
    return eq + value; // Reuse the previous operator
}
