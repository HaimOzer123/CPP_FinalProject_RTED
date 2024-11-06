#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

/**
 * @brief Derived class representing a cat.
 */

class Cat : public Animal {
public:

    /**
     * @brief Constructs a Cat object with the specified parameters.
     * @param name Name of the cat.
     * @param temp Body temperature in Celsius.
     * @param breath Respiration rate (breaths per minute).
     * @param heart Heart rate (beats per minute).
     */

    Cat(const std::string& name, double temp, double breath, double heart);

    /**
     * @brief Checks the health of the cat.
     * @return true if the cat is healthy, false otherwise.
     */

    bool check_health() const override;
};

#endif
