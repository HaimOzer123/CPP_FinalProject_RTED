#include "Cow.hpp"

/**
 * @brief Constructs a Cow object with specified attributes.
 */
Cow::Cow(const std::string& name, double temp, double breath, double heart, double milk)
    : Animal(name, temp, breath, heart), milk(milk) {}

/**
 * @brief Checks if the cow's health metrics are within the healthy range.
 * @return true if healthy, false otherwise.
 */
bool Cow::check_health() const {
    return (temp >= 38.5 && temp <= 39.5) &&
           (breath >= 26 && breath <= 50) &&
           (heart >= 48 && heart <= 84) &&
           (milk >= 30); // Milk production should be 30 liters or more
}
