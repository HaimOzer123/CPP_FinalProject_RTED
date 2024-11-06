#include "Cat.hpp"

/**
 * @brief Constructs a Cat object with specified attributes.
 */
Cat::Cat(const std::string& name, double temp, double breath, double heart)
    : Animal(name, temp, breath, heart) {}

/**
 * @brief Checks if the cat's health metrics are within the healthy range.
 * @return true if healthy, false otherwise.
 */
bool Cat::check_health() const {
    if (temp < 0 || breath < 0 || heart < 0) {
        return false;
    }
    else {
    return (temp >= 38 && temp <= 39.2) &&
           (breath >= 16 && breath <= 40) &&
           (heart >= 120 && heart <= 140);
    }
}
