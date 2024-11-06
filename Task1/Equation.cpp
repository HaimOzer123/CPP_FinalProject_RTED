#include "Equation.hpp"

Equation::Equation(double a, double b, double c) : a_(a), b_(b), c_(c), solutions_(nullptr), solutions_size_(0) {
    if (a == 0) throw std::invalid_argument("Coefficient a cannot be zero.");
    update_solutions();
}

void Equation::update_solutions() {
    delete[] solutions_;
    solutions_ = nullptr;
    solutions_size_ = 0;
}
