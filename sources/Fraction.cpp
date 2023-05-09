#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>

namespace ariel{

int greatestCommonDivisor(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a < b) {
        std::swap(a, b);
    }

    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

void Fraction::reduce() {
    int gcd = greatestCommonDivisor(_numerator, _denominator);
    _numerator /= gcd;
    _denominator /= gcd;
}

void Fraction::minus() {
if(_denominator<0 && _numerator>0)
{
    _denominator*=(-1);
    _numerator*=(-1);
return;
}
if(_denominator<0 && _numerator<0){
    _denominator*=(-1);
    _numerator*=(-1);
return;
}
if(_numerator==0){
    _denominator=1;
    _numerator=0;
    return;
}

else return;
}



Fraction ::Fraction()
{
    this->_numerator=0;
    this->_denominator=1;
}

Fraction::Fraction(int num, int denom)
    : _numerator(num), _denominator(denom)
{
    if (_denominator == 0) {
throw std::invalid_argument("Error: Denominator cannot be zero.");   
    }
    reduce();
    minus();
}

Fraction::Fraction(float value){
    if(value==0)
    {
this->_numerator=0;
this->_denominator=4;
return;
    }
   this->_numerator = value * 1000;
        this->_denominator = 1000;
        reduce();
        minus();
    }


float Fraction::toFloat() const {
    return static_cast<float>(_numerator) / static_cast<float>(_denominator);
}


int Fraction::getNumerator() const{ return this->_numerator;}
int Fraction::getDenominator() const{return this->_denominator;}


// Addition operator overloading
Fraction operator+(const Fraction& a, const Fraction& other) {
    long long num = static_cast<long long>(a._numerator) * static_cast<long long>(other._denominator) +
                    static_cast<long long>(other._numerator) * static_cast<long long>(a._denominator);

    // Check for overflow
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow occurred during addition of fractions");
    }

    int denom = a._denominator * other._denominator;
    return Fraction(static_cast<int>(num), denom);
}

Fraction operator+(float float_frac, const Fraction& frac) {
    Fraction float_fraction(float_frac);
    return frac + float_fraction;
}

Fraction operator+(const Fraction& frac, float float_frac) {
    Fraction float_fraction(float_frac);
    return  float_fraction+frac;
}

// Subtraction operator overloading
Fraction operator-(const Fraction& a, const Fraction& other) {
    long long num = static_cast<long long>(a._numerator) * static_cast<long long>(other._denominator) -
                    static_cast<long long>(other._numerator) * static_cast<long long>(a._denominator);

    // Check for overflow
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow occurred during subtraction of fractions");
    }

    int denom = a._denominator * other._denominator;
    return Fraction(static_cast<int>(num), denom);
}

Fraction operator-(float float_frac, const Fraction& frac) {
    Fraction float_fraction(float_frac);
    return float_fraction-frac;
}

Fraction operator-(const Fraction& frac, float float_frac) {
    Fraction float_fraction(float_frac);
    return frac - float_fraction;
}

// Multiplication operator overloading
Fraction operator*(const Fraction& a, const Fraction& other) {
    long long num = static_cast<long long>(a._numerator) * static_cast<long long>(other._numerator);
    long long denom = static_cast<long long>(a._denominator) * static_cast<long long>(other._denominator);

    // Check for overflow
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
        denom > std::numeric_limits<int>::max() || denom < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow occurred during multiplication of fractions");
    }

    return Fraction(static_cast<int>(num), static_cast<int>(denom));
}

Fraction operator*(float float_frac, const Fraction& frac) {
    Fraction float_fraction(float_frac);
    return frac * float_fraction;
}

Fraction operator*(const Fraction& frac, float float_frac) {
    Fraction float_fraction(float_frac);
    return frac * float_fraction;
}

// Division operator overloading
Fraction operator/(const Fraction& a, const Fraction& other) {
    if (other.getNumerator() == 0) {
        throw std::runtime_error("cant divide with zero");
    }

    long long num = static_cast<long long>(a._numerator) * static_cast<long long>(other._denominator);
    long long denom = static_cast<long long>(a._denominator) * static_cast<long long>(other._numerator);

    // Check for overflow
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
        denom > std::numeric_limits<int>::max() || denom < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow occurred during division of fractions");
    }

    return Fraction(static_cast<int>(num), static_cast<int>(denom));
}

Fraction operator/(float float_frac, const Fraction& frac) {
    Fraction float_fraction(float_frac);
    return float_fraction / frac;
}

Fraction operator/(const Fraction& frac, float float_frac) {
    Fraction float_fraction(float_frac);
    if (float_fraction.getNumerator()==0)
    {
throw std::runtime_error("cant divide with zero");
    }
    return frac / float_fraction;
}

bool operator==(const Fraction& numA, float numB) {
    float a = numA.toFloat();
    return std::abs(a - numB) < std::numeric_limits<float>::epsilon();
}

bool operator<(const Fraction& numA, float numB) {
    float a = numA.toFloat();
    return a < numB && std::abs(a - numB) >= std::numeric_limits<float>::epsilon();
}

bool operator>(const Fraction& numA, float numB) {
    float a = numA.toFloat();
    return a > numB && std::abs(a - numB) >= std::numeric_limits<float>::epsilon();
}

bool operator<=(const Fraction& numA, float numB) {
    float a = numA.toFloat();
    return a <= numB || std::abs(a - numB) < std::numeric_limits<float>::epsilon();
}

bool operator>=(const Fraction& numA, float numB) {
    float a = numA.toFloat();
    return a >= numB || std::abs(a - numB) < std::numeric_limits<float>::epsilon();
}






bool operator==(float numA, const Fraction& numB){
    float b = numB.toFloat();
    return std::abs(numA - b) < std::numeric_limits<float>::epsilon();
}

bool operator<( float numA, const Fraction& numB){
    float b = numB.toFloat();
    return numA < b && std::abs(numA - b) >= std::numeric_limits<float>::epsilon();
}

bool operator>(float numA, const Fraction& numB){
    float b = numB.toFloat();
    return numA > b && std::abs(numA - b) >= std::numeric_limits<float>::epsilon();
}

bool operator>=(float numA, const Fraction& numB){
    float b = numB.toFloat();
    return numA >= b || std::abs(numA - b) < std::numeric_limits<float>::epsilon();
}

bool operator<=(float numA, const Fraction& numB){
    float b = numB.toFloat();
    return numA <= b || std::abs(numA - b) < std::numeric_limits<float>::epsilon();
}

bool operator==(const Fraction& numA, const Fraction& other) {
    if(numA._numerator==0&& other._numerator==0)
    {
        return true;
    }
    if(numA._denominator*(-1)==other._denominator && numA._numerator==other._numerator*(-1))
    {
    return true;
    }
    return (numA._numerator == other._numerator) && (numA._denominator == other._denominator);
}

bool operator<(const Fraction& numA, const Fraction& other) {
    return (numA._numerator * other._denominator) < (other._numerator * numA._denominator);
}

bool operator>(const Fraction& numA, const Fraction& other) {
    return (numA._numerator * other._denominator) > (other._numerator * numA._denominator);
}

bool operator<=(const Fraction& numA, const Fraction& other) {
    return (numA._numerator * other._denominator) <= (other._numerator * numA._denominator);
}

bool operator>=(const Fraction& numA, const Fraction& other) {
    return (numA._numerator * other._denominator) >= (other._numerator * numA._denominator);
}
 

Fraction& Fraction::operator++() {
    _numerator += _denominator;
    return *this;
}
Fraction& Fraction::operator--() {
    _numerator -= _denominator;
    return *this;
}
Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    _numerator += _denominator;
    return temp;
}
Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    _numerator -= _denominator;
    return temp;
}



//taken form gpt
std::istream& operator>>(std::istream& inputStream, Fraction& fraction)
{
    int num = 0, denom = 1;
    int sign = 1;
    bool in_num = true;

    // Read the numerator
    if (!(inputStream >> num))
    {
        // Failed to read numerator
        throw std::runtime_error("Failed to read numerator");
    }

    // Check for negative sign
    char c = inputStream.peek();
    // if (c == '-')
    // {
    //     sign = -1;
    //     inputStream.ignore(1); 
    // }


    // Read the denominator
    if (!(inputStream >> denom))
    {
        // Failed to read denominator
        throw std::runtime_error("Failed to read denominator");
    }

    if (denom == 0)
    {
        // Denominator cannot be zero
        throw std::runtime_error("Denominator cannot be zero");
    }

    // Handle the case where the numerator is zero and the denominator is not negative
    if (num == 0 && denom > 0)
    {
        fraction.setNumerator(num);
        fraction.setDenominator(denom);
        return inputStream;
    }

    // Handle the case where the numerator is zero and the denominator is negative
    if (num == 0 && denom < 0)
    {
        num *= -1;
        denom *= -1;
        fraction.setNumerator(num);
        fraction.setDenominator(denom);
        return inputStream;
    }

    fraction.setNumerator(num * sign);
    fraction.setDenominator(denom);

    return inputStream;
}


std::ostream& operator<<(std::ostream& stream, const Fraction& frac)
{
Fraction t = frac;
// if the denominator is negative flip signs
if (t.getDenominator() < 0)
{
t.setNumerator(-t.getNumerator());
t.setDenominator(-t.getDenominator());
}
stream << t.getNumerator() << "/" << t.getDenominator();
return stream;
}
}
 
