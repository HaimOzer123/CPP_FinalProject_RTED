# CPP_FinalProject_RTED
# Haim Ozer - 316063569 - Nov/2024
#
# Quadratic Equation Solver - Task 1

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
   g++ main.cpp Equation.cpp -o test

2. **Run the Program** 
    ./test

3. **Install Doxygen (if needed)**
    sudo apt-get install doxygen
    
    And open docs/html/index.html to view the generated documentation.
