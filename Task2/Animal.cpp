#include "Animal.hpp"

/**
 * @brief Constructs an Animal object with specified attributes.
 */
Animal::Animal(const std::string& name, double temp, double breath, double heart)
    : name(name), temp(temp), breath(breath), heart(heart) {}

/**
 * @brief Gets the name of the animal.
 * @return The name of the animal.
 */
std::string Animal::get_name() const { return name; }

/**
 * @brief Gets the body temperature of the animal.
 * @return The body temperature in Celsius.
 */
double Animal::get_temp() const { return temp; }

/**
 * @brief Gets the respiration rate of the animal.
 * @return The respiration rate (breaths per minute).
 */
double Animal::get_breath() const { return breath; }

/**
 * @brief Gets the heart rate of the animal.
 * @return The heart rate (beats per minute).
 */
double Animal::get_heart() const { return heart; }
