#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

/**
 * @brief Base class representing a general animal.
 */
class Animal {
protected:
    std::string name; /**< Name of the animal */
    double temp;      /**< Body temperature in Celsius */
    double breath;    /**< Respiration rate (breaths per minute) */
    double heart;     /**< Heart rate (beats per minute) */

public:
    /**
     * @brief Constructs an Animal object with the specified parameters.
     * @param name Name of the animal.
     * @param temp Body temperature in Celsius.
     * @param breath Respiration rate (breaths per minute).
     * @param heart Heart rate (beats per minute).
     */
    Animal(const std::string& name, double temp, double breath, double heart);

    /**
     * @brief Virtual destructor for Animal class.
     */
    virtual ~Animal() = default;

    /**
     * @brief Checks if the animal is healthy.
     * @return true if healthy, false otherwise.
     */
    virtual bool check_health() const = 0;

    /**
     * @brief Gets the name of the animal.
     * @return The name of the animal.
     */
    std::string get_name() const;

    /**
     * @brief Gets the body temperature of the animal.
     * @return The body temperature in Celsius.
     */
    double get_temp() const;

    /**
     * @brief Gets the respiration rate of the animal.
     * @return The respiration rate (breaths per minute).
     */
    double get_breath() const;

    /**
     * @brief Gets the heart rate of the animal.
     * @return The heart rate (beats per minute).
     */
    double get_heart() const;
};

#endif
