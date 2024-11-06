#ifndef VET_HPP
#define VET_HPP

#include "Animal.hpp"
#include <vector>
#include <memory>
#include <iostream>

/**
 * @brief Singleton class representing a veterinary service that manages animals.
 */
class Vet {
    std::vector<std::unique_ptr<Animal>> animals; /**< Collection of animal pointers */

    /**
     * @brief Private constructor for singleton pattern.
     */
    Vet() = default;

    /**
     * @brief Private destructor for singleton pattern.
     */
    ~Vet() = default;

public:
    Vet(const Vet&) = delete;
    Vet& operator=(const Vet&) = delete;

    /**
     * @brief Retrieves the singleton instance of the Vet class.
     * @return Reference to the singleton Vet instance.
     */
    static Vet& get_instance();

    /**
     * @brief Adds an animal to the veterinary service.
     * @param animal Rvalue reference to an Animal pointer.
     */
    void add_animal(Animal* &&animal);

    /**
     * @brief Shows the names of all sick animals.
     */
    void show_sick() const;

    /**
     * @brief Shows the names of all sick dogs.
     */
    void show_sick_dogs() const;
};

#endif
