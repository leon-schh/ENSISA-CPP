#include <iostream>
#include "MatrixNumerical.h"

int main() {
    // Test matrice 3x3
    MatrixNumerical<double> m1(3, 3);
    m1.addElement(0, 0, 1); m1.addElement(0, 1, 2); m1.addElement(0, 2, 3);
    m1.addElement(1, 0, 0); m1.addElement(1, 1, 1); m1.addElement(1, 2, 4);
    m1.addElement(2, 0, 5); m1.addElement(2, 1, 6); m1.addElement(2, 2, 0);
    
    std::cout << "Matrice M1:\n";
    m1.Display(std::cout);
    
    std::cout << "\nDeterminant de M1: " << m1.getDeterminant() << "\n";
    
    // Test matrice identité
    auto identity = MatrixNumerical<double>::getIdentity(3);
    std::cout << "\nMatrice identite 3x3:\n";
    identity.Display(std::cout);
    
    // Test addition
    MatrixNumerical<double> m2(3, 3);
    m2.addElement(0, 0, 1); m2.addElement(0, 1, 0); m2.addElement(0, 2, 0);
    m2.addElement(1, 0, 0); m2.addElement(1, 1, 1); m2.addElement(1, 2, 0);
    m2.addElement(2, 0, 0); m2.addElement(2, 1, 0); m2.addElement(2, 2, 1);
    
    auto sum = m1 + m2;
    std::cout << "\nM1 + M2:\n";
    sum.Display(std::cout);
    
    // Test inverse
    try {
        auto inv = m1.getInverse();
        std::cout << "\nInverse de M1:\n";
        inv.Display(std::cout);
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << "\n";
    }
    
    return 0;
}
