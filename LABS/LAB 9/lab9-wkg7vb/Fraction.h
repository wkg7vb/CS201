#pragma once
// Walter Gilliam
// November 10, 2021
// Lab 9

#include <iostream>
using namespace std;

class Fraction
{
	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.
	private:
		int numerator;
		int denominator;
		int getGCD(int num1, int num2);

	public:
		Fraction();
		void reduce();
		friend istream& operator>> (istream& input, Fraction& fract);
		friend ostream& operator<< (ostream& output, const Fraction& fract);
		const Fraction operator+ (const Fraction& rhs);
		const Fraction operator- (const Fraction& rhs);
		const Fraction operator* (const Fraction& rhs);
		const Fraction operator/ (const Fraction& rhs);
		bool operator== (Fraction rhs);
};

