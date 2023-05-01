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
    void reduce();
    float toFloat() const;
public:
Fraction (const int& num=0, const int& denum=1)
    : _numerator(num), _denominator(denum){
        if(_denominator==0){
        throw ("error");
        }
    };

/*
*Getters
*/
int numerator() const{ return _numerator; }
int denominator() const{return _denominator;  }

/*
*Math operators
*/

//  const in the end of the operator overloading is to determine that the object woldn't modified
Fraction operator+ (const Fraction& other) const;
Fraction operator+ (const float& other) const;
friend Fraction operator+ (const float& num, const Fraction& other);
Fraction operator- (const Fraction& other) const;
Fraction operator- (const float& other) const;
friend Fraction operator- (const float& num, const Fraction& other);
Fraction operator* (const Fraction& other) const; 
Fraction operator* (const float& other) const;
friend Fraction operator* (const float& num, const Fraction& other);
Fraction operator/ (const Fraction& other) const; 
Fraction operator/ (const float& other) const; 
friend Fraction operator/ (const float& num, const Fraction& other);


//float operator* (const Fraction& other )const;
/*
*Comparison operators
*/
friend bool operator==(const Fraction& numA, float numB);
friend bool operator<( const Fraction& numA, float numB);
friend bool operator>(const Fraction& numA, float numB);
friend bool operator>=(const Fraction& numA, float numB);
friend bool operator<=(const Fraction& numA, float numB);



bool operator==(const Fraction& numB)const;
bool operator<( const Fraction& numB)const;
bool operator>(const Fraction& numB)const;
bool operator>=(const Fraction& numB)const;
bool operator<=(const Fraction& numB)const;

bool operator==(float numA);
bool operator<(float numA);
bool operator>(float numA);
bool operator>=(float numA);
bool operator<=(float numA);
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
friend std::ostream& operator<<(std::ostream& output, const Fraction& numA);
friend std::istream& operator>>(std::istream& input , Fraction& numA);






};
}





