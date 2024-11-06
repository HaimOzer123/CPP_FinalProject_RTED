#include "Equation.hpp"

// Constructor with three parameters (pa, pb, pc) that initializes the coefficients
// and sets the solutions array to nullptr initially
Equation::Equation(double pa, double pb, double pc) : pa(pa), pb(pb), pc(pc), solutions(nullptr), solutions_size(0) {
    if (pa == 0) throw std::invalid_argument("Coefficient pa cannot be zero.");
    update_solutions();
}

// Copy constructor: Initializes a new Equation by copying another Equation's coefficients and solutions
Equation::Equation(const Equation& other) : pa(other.pa), pb(other.pb), pc(other.pc), solutions_size(other.solutions_size) {
    solutions = new double[solutions_size];
    for (std::size_t i = 0; i < solutions_size; ++i)
        solutions[i] = other.solutions[i];
}

// Copy assignment operator: Assigns another Equation to this one by deep copying its coefficients and solutions
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

// Destructor: Releases memory allocated for the solutions array
Equation::~Equation() {
    delete[] solutions;
}

// Move constructor: Transfers ownership of another Equation's resources to this one
Equation::Equation(Equation&& other) noexcept : pa(other.pa), pb(other.pb), pc(other.pc), solutions(other.solutions), solutions_size(other.solutions_size) {
    other.solutions = nullptr; // Nullify other's pointer to prevent double delete
    other.solutions_size = 0;
}

// Move assignment operator: Moves resources from another Equation to this one, releasing existing resources
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

// Getter for coefficient pa
double Equation::get_pa() const { return pa; }

// Getter for coefficient pb
double Equation::get_pb() const { return pb; }

// Getter for coefficient pc
double Equation::get_pc() const { return pc; }

// Setter for coefficient pa with a check to prevent setting pa to zero (non-quadratic equation)
// Calls update_solutions to recalculate solutions after changing pa
void Equation::set_pa(double pa) {
    if (pa == 0) throw std::invalid_argument("Coefficient pa cannot be zero.");
    this->pa = pa;
    update_solutions();
}

// Setter for coefficient pb; recalculates solutions after setting pb
void Equation::set_pb(double pb) {
    this->pb = pb;
    update_solutions();
}

// Setter for coefficient pc; recalculates solutions after setting pc
void Equation::set_pc(double pc) {
    this->pc = pc;
    update_solutions();
}

// Returns the size of the solutions array
std::size_t Equation::get_solutions_size() const {
    return solutions_size;
}

// Returns a const pointer to the solutions array
const double* Equation::get_solutions() const {
    return solutions;
}

// Private method to calculate and update the solutions array based on current values of pa, pb, and pc
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

// Overloaded << operator to display the equation in the required format: "pa X^2 + pb X + pc = 0"
std::ostream& operator<<(std::ostream& os, const Equation& eq) {
    os << std::fixed << std::setprecision(1)
       << eq.pa << " X^2 + " << eq.pb << " X + " << eq.pc << " = 0";
    return os;
}

// Overloaded + operator to add two Equation objects, resulting in a new Equation
Equation operator+(const Equation& lhs, const Equation& rhs) {
    return Equation(lhs.pa + rhs.pa, lhs.pb + rhs.pb, lhs.pc + rhs.pc);
}

// Overloaded + operator to add a double to an Equation's pc coefficient, resulting in a new Equation
Equation operator+(const Equation& eq, double value) {
    return Equation(eq.pa, eq.pb, eq.pc + value);
}

// Overloaded + operator to add an Equation to a double (double on the left), resulting in a new Equation
Equation operator+(double value, const Equation& eq) {
    return eq + value; // Re
