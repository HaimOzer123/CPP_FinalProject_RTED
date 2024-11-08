 
# CPP_FinalProject_RTED
Haim Ozer - 316063569 - Nov/2024

## Quadratic Equation Solver - Task 1

This project provides a C++ implementation of a **Quadratic Equation Solver** for equations of the form \( ax^2 + bx + c = 0 \).
It includes an `Equation` class with functionality to calculate solutions, manage resources, and perform operations with overloaded operators.


## Features

- **Equation Initialization** with coefficients \( a \), \( b \), and \( c \).
- **Solution Calculation** based on the discriminant.
- **Operator Overloading** for adding equations and constants, and for formatted output.
- **Resource Management** with the Rule of Five for safe memory handling.
- **Documentation with Doxygen** 

## Setup Instructions

1. **Compile the Project**:
   g++ *.cpp  -o test

2. **Run the Program** 
    ./test

3. **Install Doxygen (if needed)**
    sudo apt-get install doxygen
    
    And open **docs/html/index.html** to view the generated documentation.

## Veterinary Health Management System - Task 2

This task implements a **Veterinary Health Management System** to monitor and manage the health of various animals using C++ concepts like inheritance, abstract classes, and the singleton design pattern. 
It includes an abstract base `Animal` class and derived classes for `Dog`, `Cat`, and `Cow`, each with specific health-check criteria.

### Features

- **Inheritance and Polymorphism**: Abstract `Animal` class with derived classes for specific animal types.
- **Health Check**: Each animal type has its own criteria for determining health.
- **Singleton Pattern**: The `Vet` class is implemented as a singleton to manage animal objects.
- **Smart Pointers**: Utilizes `unique_ptr` for automatic memory management.
- **Documentation with Doxygen**: Generates documentation for better code understanding.

## Health Criteria for Animals

The health criteria for each type of animal are as follows:

| Type | Body Temperature (°C) | Respiratory Rate (breaths/min) | Heart Rate (beats/min)         | Milk Production            |
|------|------------------------|--------------------------------|--------------------------------|-----------------------------|
| Dog  | 38.0 - 39.2            | 10 - 35                        | 60 - 100 if large, 100 - 140 if small | N/A                         |
| Cat  | 38.0 - 39.2            | 16 - 40                        | 120 - 140                      | N/A                         |
| Cow  | 38.5 - 39.5            | 26 - 50                        | 48 - 84                        | 30 or more liters per day   |


### Setup Instructions

1. **Compile the Project**:
   g++ *.cpp -std=c++14 -o test

2. **Run the Program** 
    ./test

3. **Install Doxygen (if needed)**
    sudo apt-get install doxygen
    
    And open **docs/html/index.html** to view the generated documentation.
