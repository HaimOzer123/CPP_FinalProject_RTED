#include "Dog.hpp"

/**
 * @brief Constructs a Dog object with specified attributes.
 */
Dog::Dog(const std::string& name, double temp, double breath, double heart, bool is_large)
    : Animal(name, temp, breath, heart), is_large(is_large) {}

/**
 * @brief Checks if the dog's health metrics are within the healthy range.
 * @return true if healthy, false otherwise.
 */
bool Dog::check_health() const {
    return (temp >= 38 && temp <= 39.2) &&
           (breath >= 10 && breath <= 35) &&
           ((is_large && heart >= 60 && heart <= 100) ||
            (!is_large && heart >= 100 && heart <= 140));
}
