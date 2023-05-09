#pragma once
#include <iostream>
#include <stdexcept>

 /**
  * header file for Fraction class
  * 
  * @author Noam Teshuva
  * 
 */



namespace ariel {
class Fraction{

private:
    int _numerator ;
    int _denominator;

public:
/*
*constructors
*/
Fraction();
Fraction(float value);
Fraction (int num , int denom);
float toFloat()const;
void reduce();
void minus();
/*
*Getters
*/
int getNumerator() const;
int getDenominator() const;


/*
*Setters
*/
void setNumerator(const int& num) { _numerator = num; }
void setDenominator(const int& denum) {
    if (denum == 0) {
           throw ("error");
    }
     _denominator = denum;
    }

//  const in the end of the operator overloading is to determine that the object woldn't modified
friend Fraction operator+(const Fraction& numA, const Fraction& other);
friend Fraction operator+(float float_frac, const Fraction& frac);
friend Fraction operator+(const Fraction& frac, float float_frac);
friend Fraction operator-(const Fraction& numA, const Fraction& other);
friend Fraction operator-(float float_frac, const Fraction& frac);
friend Fraction operator-(const Fraction& frac, float float_frac);
friend Fraction operator*(const Fraction& numA, const Fraction& other);
friend Fraction operator*(float float_frac, const Fraction& frac);
friend Fraction operator*(const Fraction& frac, float float_frac);
friend Fraction operator/(const Fraction& numA, const Fraction& other);
friend Fraction operator/(float float_frac, const Fraction& frac);
friend Fraction operator/(const Fraction& frac, float float_frac);

//float operator* (const Fraction& other )const;
/*
*Comparison operators
*/
friend bool operator==(const Fraction& numA, float numB);
friend bool operator<( const Fraction& numA, float numB);
friend bool operator>(const Fraction& numA, float numB);
friend bool operator>=(const Fraction& numA, float numB);
friend bool operator<=(const Fraction& numA, float numB);


friend bool operator==(float numA, const Fraction& numB);
friend bool operator<( float numA, const Fraction& numB);
friend bool operator>(float numA, const Fraction& numB);
friend bool operator>=(float numA, const Fraction& numB);
friend bool operator<=(float numA, const Fraction& numB);

friend bool operator==(const Fraction& numA, const Fraction& other) ;
friend bool operator<(const Fraction& numA,const Fraction& other) ;
friend bool operator>(const Fraction& numA,const Fraction& other) ;
friend bool operator<=(const Fraction& numA,const Fraction& other) ;
friend bool operator>=(const Fraction& numA,const Fraction& other) ;

/*
* Increment and decrement, prefix and and postfix
*/
//prefixs
Fraction& operator++();
Fraction& operator--();
//postfix, the int is used to distingush between the two operators
Fraction operator++(int);
Fraction operator--(int);

/*
*Friend global  IO oprators io stands for input output
* takend from the course git
*/
friend std::ostream &operator<<(std::ostream &stream, const Fraction &frac);
friend std::istream& operator>>(std::istream& ios, Fraction& frac);




};
}





