#ifndef COW_HPP
#define COW_HPP

#include "Animal.hpp"

/**
 * @brief Derived class representing a cow.
 */
class Cow : public Animal {
    double milk; /**< Daily milk production in liters */

public:
    /**
     * @brief Constructs a Cow object with the specified parameters.
     * @param name Name of the cow.
     * @param temp Body temperature in Celsius.
     * @param breath Respiration rate (breaths per minute).
     * @param heart Heart rate (beats per minute).
     * @param milk Daily milk production in liters.
     */
    Cow(const std::string& name, double temp, double breath, double heart, double milk);

    /**
     * @brief Checks the health of the cow.
     * @return true if the cow is healthy, false otherwise.
     */
    bool check_health() const override;
};

#endif
