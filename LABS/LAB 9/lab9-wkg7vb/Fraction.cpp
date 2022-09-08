// WAlter Gilliam
// November 10, 2021
// Lab 10

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

Fraction :: Fraction()
{
	numerator = 0;
	denominator = 0;
}

istream& operator>> (istream& input, Fraction& fract)
{
	char temp;
	input >> fract.numerator >> temp >> fract.denominator;
	return input;
}

ostream& operator<< (ostream& output, const Fraction& fract)
{
	output << fract.numerator << "/" << fract.denominator;
	return output;
}

const Fraction Fraction :: operator+ (const Fraction& rhs)
{
	Fraction result;
	result.numerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
	result.denominator = this->denominator * rhs.denominator;
	result.reduce();
	return result;
}

const Fraction Fraction :: operator- (const Fraction& rhs)
{
	Fraction result;
	result.numerator = this->numerator * rhs.denominator - rhs.numerator * this->denominator;
	result.denominator = this->denominator * rhs.denominator;
	result.reduce();
	return result;
}

const Fraction Fraction :: operator* (const Fraction& rhs)
{
	Fraction result;
	result.numerator = this->numerator * rhs.numerator;
	result.denominator = this->denominator * rhs.denominator;
	result.reduce();
	return result;
}

const Fraction Fraction :: operator/ (const Fraction& rhs)
{
	Fraction result;
	result.numerator = this->numerator * rhs.denominator;
	result.denominator = this->denominator * rhs.numerator;
	result.reduce();
	return result;
}

//Since == returns whether something is equal (true) or not equal (false), you should return true 
//or false based on whether the numerators and denominators are equal.

//^that is from the Lab 09-1 (1).docx on Canvas
//I would have made it so that 1/1 == -1/-1 returns true but acording to these parameters, that statement will return false.
bool Fraction :: operator== (Fraction rhs)
{
	if (this->numerator == rhs.numerator && this->denominator == rhs.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	if (denominator < 0)
	{
		numerator /= -gcd;
		denominator /= -gcd;
	}
	else
	{
		numerator /= gcd;
		denominator /= gcd;
	}
	
}

/* 
General pattern for overloaded operators: 
   1. Declare new object as local variable 
   2. Assign values as needed--in this case, to numerator & denominator
   3. return new object
Note that for most operators, the return type is a const object or const reference to object. 
That's so this: 

A + B = C; 

isn't legal, but 

C = A + B; 

is. 
*/ 
