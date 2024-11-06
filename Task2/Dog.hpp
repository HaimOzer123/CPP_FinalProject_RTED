#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

/**
 * @brief Derived class representing a dog.
 */
class Dog : public Animal {
    bool is_large; /**< Boolean indicating if the dog is a large breed */

public:
    /**
     * @brief Constructs a Dog object with the specified parameters.
     * @param name Name of the dog.
     * @param temp Body temperature in Celsius.
     * @param breath Respiration rate (breaths per minute).
     * @param heart Heart rate (beats per minute).
     * @param is_large True if the dog is a large breed, false otherwise.
     */
    Dog(const std::string& name, double temp, double breath, double heart, bool is_large);

    /**
     * @brief Checks the health of the dog.
     * @return true if the dog is healthy, false otherwise.
     */
    bool check_health() const override;
};

#endif 