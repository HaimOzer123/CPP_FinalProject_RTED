#include "Vet.hpp"
#include "Dog.hpp"

/**
 * @brief Retrieves the singleton instance of the Vet class.
 * @return Reference to the singleton Vet instance.
 */
Vet& Vet::get_instance() {
    static Vet instance;
    return instance;
}

/**
 * @brief Adds an animal to the veterinary service.
 * @param animal Rvalue reference to an Animal pointer.
 */
void Vet::add_animal(Animal* &&animal) {
    animals.emplace_back(animal);
}

/**
 * @brief Shows the names of all sick animals.
 */
void Vet::show_sick() const {
    for (const auto& animal : animals) {
        if (!animal->check_health()) {
            std::cout << animal->get_name() << " ";
        }
    }
    std::cout << std::endl;
}

/**
 * @brief Shows the names of all sick dogs.
 */
void Vet::show_sick_dogs() const {
    for (const auto& animal : animals) {
        auto* dog = dynamic_cast<Dog*>(animal.get());
        if (dog && !dog->check_health()) {
            std::cout << dog->get_name() << " ";
        }
    }
    std::cout << std::endl;
}
