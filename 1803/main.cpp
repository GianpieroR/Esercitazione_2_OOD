#include <iostream>
#include "complex.hpp"


int main(void) {

    // Definiamo due numeri complessi c1 e c2 e facciamo agire su di loro i metodi e gli operator
    // creati nella classe template ComplexNumber

    ComplexNumber<float> c1(1.0, 2.0);
    ComplexNumber<float> c2(3.0, -4.0);
    
    // stampiamo i numeri che abbiamo preso in oggetto specificando le componenti

    std::cout << "c1 = " << c1 << "; la sua parte reale è " <<  c1.getReal() << " e la sua parte immaginaria è " << c1.getImag() << std::endl;
    std::cout << "c2 = " << c2 << "; la sua parte reale è " <<  c2.getReal() << " e la sua parte immaginaria è " << c2.getImag() << std::endl;

    // stampiamo la somma

    std::cout << c1 << " + " << c2 << " = " << c1+c2 << std::endl;

    // stampiamo il prodotto

    std::cout << c1 << " * " << c2 << " = " << c1*c2 << std::endl;

    // stampiamo il coniugato di c1

    std::cout << "Coniugato di " << c1 << " = " << c1.coniugato() << std::endl;
    
    return 0;
}