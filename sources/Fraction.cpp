#include "Fraction.hpp"
#include <iostream>

namespace ariel{


//gpt
int greatestCommonDivisor(int a, int b) {
    // Ensure a and b are positive
    a = abs(a);
    b = abs(b);

    // Swap if necessary to ensure a >= b
    if (a < b) {
        std::swap(a, b);
    }

    // Compute GCD using Euclidean algorithm
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

void Fraction:: reduce(){
   int gcd = greatestCommonDivisor(_numerator, _denominator);
    _numerator /= gcd;
    _denominator /= gcd;
}

float Fraction::toFloat() const {
    return static_cast<float>(_numerator) / static_cast<float>(_denominator);
}



/*
*Math operators
*/
Fraction Fraction::operator+(const Fraction& other) const {
    int newNumerator = _numerator * other._denominator + other._numerator * _denominator;
    int newDenominator = _denominator * other._denominator;
    Fraction result(newNumerator, newDenominator);
    result.reduce();
    return result;
}
Fraction Fraction::operator+(const float& other) const {
    Fraction result(*this);
    Fraction otherFraction(other);
    result._numerator = result._numerator * otherFraction._denominator + otherFraction._numerator * result._denominator;
    result._denominator = result._denominator * otherFraction._denominator;
    result.reduce();
    return result;
}

Fraction operator+(const float& num, const Fraction& other) {
    Fraction result(other);
    Fraction numFraction(num);
    result._numerator = result._numerator + numFraction._numerator * result._denominator;
    result.reduce();
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    int newNumerator = _numerator * other._denominator - other._numerator * _denominator;
    int newDenominator = _denominator * other._denominator;
    Fraction result(newNumerator, newDenominator);
    result.reduce();
    return result;
}

Fraction Fraction::operator-(const float& other) const {
    Fraction result(*this);
    Fraction otherFraction(other);
    result._numerator = result._numerator * otherFraction._denominator - otherFraction._numerator * result._denominator;
    result._denominator = result._denominator * otherFraction._denominator;
    result.reduce();
    return result;
}

Fraction operator-(const float& num, const Fraction& other) {
    Fraction result(other);
    Fraction numFraction(num);
    result._numerator = numFraction._numerator * result._denominator - result._numerator;
    result.reduce();
    return result;
}


Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result(*this);
    result._numerator = result._numerator * other._numerator;
    result._denominator = result._denominator * other._denominator;
    result.reduce();
    return result;
}

Fraction Fraction::operator*(const float& other) const {
    Fraction result(*this);
    result._numerator = result._numerator * other;
    result.reduce();
    return result;
}

Fraction operator*(const float& num, const Fraction& other) {
    Fraction result(other);
    result._numerator = num * result._numerator;
    result.reduce();
    return result;
}

Fraction Fraction::operator/(const float& other) const {
    Fraction result(*this);
    result._denominator = result._denominator * other;
    result.reduce();
    return result;
}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction result(*this);
    result._numerator = result._numerator * other._denominator;
    result._denominator = result._denominator * other._numerator;
    result.reduce();
    return result;
}

Fraction operator/(const float& num, const Fraction& other) {
    Fraction result(other);
    result._numerator = num * result._denominator;
    result.reduce();
    return result;
}


/*
*Comparison operators
*/
bool operator==(const Fraction& numA, float numB) {
    return numA.toFloat() == numB;
}

bool operator<(const Fraction& numA, float numB) {
    return numA.toFloat() < numB;
}

bool operator>(const Fraction& numA, float numB) {
    return numA.toFloat() > numB;
}

bool operator<=(const Fraction& numA, float numB) {
    return numA.toFloat() <= numB;
}

bool operator>=(const Fraction& numA, float numB) {
    return numA.toFloat() >= numB;
}


bool Fraction::operator==(const Fraction& other) const {
    return (_numerator == other._numerator) && (_denominator == other._denominator);
}

bool Fraction::operator<(const Fraction& other) const {
    return (_numerator * other._denominator) < (other._numerator * _denominator);
}

bool Fraction::operator>(const Fraction& other) const {
    return (_numerator * other._denominator) > (other._numerator * _denominator);
}

bool Fraction::operator>=(const Fraction& other) const {
    return (_numerator * other._denominator) >= (other._numerator * _denominator);
}

bool Fraction::operator<=(const Fraction& other) const {
    return (_numerator * other._denominator) <= (other._numerator * _denominator);
}


bool Fraction::operator==(float numA) {
    return (_numerator == numA * _denominator);
}

bool Fraction::operator<(float numA) {
    return (_numerator < numA * _denominator);
}

bool Fraction::operator>(float numA) {
    return (_numerator > numA * _denominator);
}

bool Fraction::operator>=(float numA) {
    return (_numerator >= numA * _denominator);
}

bool Fraction::operator<=(float numA) {
    return (_numerator <= numA * _denominator);
}



/*
* Increment and decrement, prefix and and postfix
*/
Fraction& Fraction::operator++() {
    _numerator += _denominator;
    return *this;
}

Fraction& Fraction::operator--() {
    _numerator -= _denominator;
    return *this;
}

Fraction Fraction::operator++(int dummy) {
    Fraction oldVal = *this;
    _numerator += _denominator;
    return oldVal;
}

Fraction Fraction::operator--(int dummy) {
    Fraction oldVal = *this;
    _numerator -= _denominator;
    return oldVal;
}





/*
*Friend global  IO oprators io stands for input output
* takend from the course git
*/
std::ostream& operator<<(std::ostream& output, const Fraction& numA) {
    output << numA.numerator() << "/" << numA.denominator();
    return output;
}
std::istream& operator>>(std::istream& input, Fraction& numA){ return input;};
}
 
