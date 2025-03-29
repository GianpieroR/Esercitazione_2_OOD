#include <iostream>
#include <concepts>
#pragma once

// Concept per vincolare il tipo T a essere un tipo floating-point
//template <typename T> requires std::floating_point<T>
// concept FloatingPoint = std::floating_point<T>;

//Classe template ComplexNumber
template <typename T> requires std::floating_point<T>
class ComplexNumber 
{
//private:
    T real;
    T imag;

public:
    // Costruttore di default
    ComplexNumber() 
        : real(0), imag(0) 
    {}
    
    //Costruttore user-defined
    explicit ComplexNumber(T r)
        : real(r), imag(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
    ComplexNumber(T r, T i) 
        : real(r), imag(i) 
    {}

    // Metodo per ottenere il coniugato
    ComplexNumber coniugato() const {
        return ComplexNumber(real, -imag);
    }

    // Metodi per ottenere parte reale e immaginaria
    T getReal() const { return real; }
    T getImag() const { return imag; }

    // Overload operatore +=
    ComplexNumber& operator+=(const ComplexNumber& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Overload operatore +
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Overload operatore *=
    ComplexNumber& operator*=(const ComplexNumber& other) {
        T newReal = real * other.real - imag * other.imag;
        T newImag = real * other.imag + imag * other.real;
        real = newReal;
        imag = newImag;
        return *this;
    }

    // Overload operatore *
    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(real * other.real - imag * other.imag,
                             real * other.imag + imag * other.real);
    }

     //  Overload per l'operatore << (output)
     friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
        os << c.real;
        if (c.imag >= 0) os << "+";
        os << c.imag << "i";
        return os;
    }

    //  Overload degli operatori tra tipi diversi (float e double)
    template <typename U>
    auto operator+(const ComplexNumber<U>& other) const {
        using ResultType = decltype(T{} + U{});  // Determina il tipo più preciso tra T e U
        return complex_number<ResultType>(
            real + static_cast<ResultType>(other.real),
            imag + static_cast<ResultType>(other.imag)
        );
    }

    template <typename U>
    auto operator*(const ComplexNumber<U>& other) const {
        using ResultType = decltype(T{} + U{});  // Determina il tipo più preciso tra T e U
        return complex_number<ResultType>(
            real * static_cast<ResultType>(other.real) - imag * static_cast<ResultType>(other.imag),
            real * static_cast<ResultType>(other.imag) + imag * static_cast<ResultType>(other.real)
        );
    }
};