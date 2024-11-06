#include <iostream>
#include "Vet.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Cow.hpp"

int main() {
    Vet& vet = Vet::get_instance();

    // Adding animals to the vet's collection
    vet.add_animal(new Dog("dog1", 38.5, 20, 80, true));   // Healthy large dog
    vet.add_animal(new Dog("dog2", 40.0, 20, 80, true));   // Unhealthy dog (high temp)
    vet.add_animal(new Cat("cat1", 38.7, 30, 130));        // Healthy cat
    vet.add_animal(new Cat("cat2", 38.7, 42, 130));        // Unhealthy cat (high breath)
    vet.add_animal(new Cow("cow1", 39.0, 37, 70, 32));     // Healthy cow
    vet.add_animal(new Cow("cow2", 39.0, 37, 70, 20));     // Unhealthy cow (low milk production)

    // Checking for sick animals
    vet.show_sick(); // Output: dog2 cat2 cow2
    vet.show_sick_dogs(); // Output: dog2

    return 0;
}
