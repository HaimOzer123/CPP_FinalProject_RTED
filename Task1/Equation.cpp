#include "Equation.hpp"

// Constructor with three parameters (a, b, c) that initializes the coefficients
// and sets the solutions array to nullptr initially
Equation::Equation(double a, double b, double c) : a_(a), b_(b), c_(c), solutions_(nullptr), solutions_size_(0) {
    if (a == 0) throw std::invalid_argument("Coefficient a cannot be zero.");
    update_solutions();
}

// Copy constructor: Initializes a new Equation by copying another Equation's coefficients and solutions
Equation::Equation(const Equation& other) : a_(other.a_), b_(other.b_), c_(other.c_), solutions_size_(other.solutions_size_) {
    solutions_ = new double[solutions_size_];
    for (std::size_t i = 0; i < solutions_size_; ++i)
        solutions_[i] = other.solutions_[i];
}

// Copy assignment operator: Assigns another Equation to this one by deep copying its coefficients and solutions
Equation& Equation::operator=(const Equation& other) {
    if (this == &other) return *this; // Handle self-assignment
    delete[] solutions_; // Release old memory
    a_ = other.a_;
    b_ = other.b_;
    c_ = other.c_;
    solutions_size_ = other.solutions_size_;
    solutions_ = new double[solutions_size_];
    for (std::size_t i = 0; i < solutions_size_; ++i)
        solutions_[i] = other.solutions_[i];
    return *this;
}

// Destructor: Releases memory allocated for the solutions array
Equation::~Equation() {
    delete[] solutions_;
}

// Move constructor: Transfers ownership of another Equation's resources to this one
Equation::Equation(Equation&& other) noexcept : a_(other.a_), b_(other.b_), c_(other.c_), solutions_(other.solutions_), solutions_size_(other.solutions_size_) {
    other.solutions_ = nullptr; // Nullify other's pointer to prevent double delete
    other.solutions_size_ = 0;
}

// Move assignment operator: Moves resources from another Equation to this one, releasing existing resources
Equation& Equation::operator=(Equation&& other) noexcept {
    if (this != &other) {
        delete[] solutions_; // Release existing resources
        a_ = other.a_;
        b_ = other.b_;
        c_ = other.c_;
        solutions_ = other.solutions_;
        solutions_size_ = other.solutions_size_;
        other.solutions_ = nullptr; // Nullify other's pointer
        other.solutions_size_ = 0;
    }
    return *this;
}

// Getter for coefficient a
double Equation::get_a() const { return a_; }

// Getter for coefficient b
double Equation::get_b() const { return b_; }

// Getter for coefficient c
double Equation::get_c() const { return c_; }

// Setter for coefficient a with a check to prevent setting a to zero (non-quadratic equation)
// Calls update_solutions to recalculate solutions after changing a
void Equation::set_a(double a) {
    if (a == 0) throw std::invalid_argument("Coefficient a cannot be zero.");
    a_ = a;
    update_solutions();
}

// Setter for coefficient b; recalculates solutions after setting b
void Equation::set_b(double b) {
    b_ = b;
    update_solutions();
}

// Setter for coefficient c; recalculates solutions after setting c
void Equation::set_c(double c) {
    c_ = c;
    update_solutions();
}

// Returns the size of the solutions array
std::size_t Equation::get_solutions_size() const {
    return solutions_size_;
}

// Returns a const pointer to the solutions array
const double* Equation::get_solutions() const {
    return solutions_;
}

// Private method to calculate and update the solutions array based on current values of a, b, and c
void Equation::update_solutions() {
    delete[] solutions_; // Release previous solutions
    double discriminant = b_ * b_ - 4 * a_ * c_; // Calculate discriminant
    if (discriminant > 0) {
        solutions_size_ = 2;
        solutions_ = new double[2];
        solutions_[0] = (-b_ + std::sqrt(discriminant)) / (2 * a_); // First root
        solutions_[1] = (-b_ - std::sqrt(discriminant)) / (2 * a_); // Second root
    } else if (discriminant == 0) {
        solutions_size_ = 1;
        solutions_ = new double[1];
        solutions_[0] = -b_ / (2 * a_); // Single root
    } else {
        solutions_size_ = 0; // No real roots
        solutions_ = nullptr;
    }
}

// Overloaded << operator to display the equation in the required format: "a X^2 + b X + c = 0"
std::ostream& operator<<(std::ostream& os, const Equation& eq) {
    os << std::fixed << std::setprecision(1)
       << eq.a_ << " X^2 + " << eq.b_ << " X + " << eq.c_ << " = 0";
    return os;
}

// Overloaded + operator to add two Equation objects, resulting in a new Equation
Equation operator+(const Equation& lhs, const Equation& rhs) {
    return Equation(lhs.a_ + rhs.a_, lhs.b_ + rhs.b_, lhs.c_ + rhs.c_);
}

// Overloaded + operator to add a double to an Equation's c coefficient, resulting in a new Equation
Equation operator+(const Equation& eq, double value) {
    return Equation(eq.a_, eq.b_, eq.c_ + value);
}

// Overloaded + operator to add an Equation to a double (double on the left), resulting in a new Equation
Equation operator+(double value, const Equation& eq) {
    return eq + value; // Reuse the previous operator
}
