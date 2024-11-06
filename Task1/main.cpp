#include <iostream>
#include "Equation.hpp"

int main() {
    using namespace std;

    // Test creation of an Equation and display it
    cout << "Creating Equation eq1 with coefficients (10, 20, 30):" << endl;
    Equation eq1(10, 20, 30);
    cout << "Equation: " << eq1 << endl; // 10 X^2 + 20 X + 30 = 0
    cout << "Number of solutions: " << eq1.get_solutions_size() << endl; // 0

    if (eq1.get_solutions_size() > 0) {
        cout << "Solutions: ";
        for (std::size_t i = 0; i < eq1.get_solutions_size(); ++i) {
            cout << eq1.get_solutions()[i] << " ";
        }
        cout << endl;
    }

    // Test setting a new value for coefficient c
    cout << "\nModifying eq1 by adding -20 to c:" << endl;
    eq1 = -20 + eq1;
    cout << "Updated Equation: " << eq1 << endl; // 10 X^2 + 20 X + 10 = 0
    cout << "Number of solutions: " << eq1.get_solutions_size() << endl; // 2

    if (eq1.get_solutions_size() > 0) {
        cout << "Solutions: ";
        for (std::size_t i = 0; i < eq1.get_solutions_size(); ++i) {
            cout << eq1.get_solutions()[i] << " ";
        }
        cout << endl;
    }

    // Test addition of two Equation objects
    cout << "\nCreating eq2 (coefficients 1, 5, 3) and eq3 (coefficients 2, 6, 4):" << endl;
    Equation eq2(1, 5, 3);
    Equation eq3(2, 6, 4);
    Equation eq_sum = eq2 + eq3;
    cout << "eq2: " << eq2 << endl; // 1 X^2 + 5 X + 3 = 0
    cout << "eq3: " << eq3 << endl;  // 2 X^2 + 6 X + 4 = 0
    cout << "Sum (eq2 + eq3): " << eq_sum << endl; // 3 X^2 + 11 X + 7 = 0

    // Test case with two real solutions
    cout << "\nCreating eq4 with coefficients (1, 3, -4):" << endl;
    Equation eq4(1, 3, -4);
    cout << "Equation: " << eq4 << endl; // 1 X^2 + 3 X - 4 = 0
    cout << "Number of solutions: " << eq4.get_solutions_size() << endl; // 2

    if (eq4.get_solutions_size() > 0) {
        cout << "Solutions: ";
        for (std::size_t i = 0; i < eq4.get_solutions_size(); ++i) {
            cout << eq4.get_solutions()[i] << " ";
        }
        cout << endl;
    }

    // Test edge case with a single real solution
    cout << "\nCreating eq5 with coefficients (1, 2, 1) (should have one real solution):" << endl;
    Equation eq5(1, 2, 1);
    cout << "Equation: " << eq5 << endl;
    cout << "Number of solutions: " << eq5.get_solutions_size() << endl;

    if (eq5.get_solutions_size() > 0) {
        cout << "Solutions: ";
        for (std::size_t i = 0; i < eq5.get_solutions_size(); ++i) {
            cout << eq5.get_solutions()[i] << " ";
        }
        cout << endl;
    }

    // Test case with no real solutions
    cout << "\nCreating eq6 with coefficients (1, 0, 4) (should have no real solutions):" << endl;
    Equation eq6(1, 0, 4);
    cout << "Equation: " << eq6 << endl; // 1 X^2 + 4 = 0
    cout << "Number of solutions: " << eq6.get_solutions_size() << endl; // 0

    if (eq6.get_solutions_size() == 0) {
        cout << "No real solutions" << endl; // No real solutions
    }

    return 0;
}
