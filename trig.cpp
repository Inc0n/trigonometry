#include "trig.h"
#include <iostream>

using namespace std;

// start of public methods
double Trig::tan(float angle) {
	return this->compute(angle, &Trig::m_sine) / compute(angle, &Trig::m_cosine);
}

double Trig::sine(float angle) {
	return this->compute(angle, &Trig::m_sine);
}

double Trig::cosine(float angle) {
	return this->compute(angle, &Trig::m_cosine);
}

// private methods
float Trig::deg_rad(int degree) {
	return PI / (180.0 / degree);
}

int Trig::m_sine(int i) {
	return 2 * i + 1;
}

int Trig::m_cosine(int i) {
	return 2 * i;
}

float pow(float base, int index) {
	float r_val = base;
	for (; index > 1; index--) 
		r_val *= base;
	
	if (index == 0) {
		return 1;		
	}
	return r_val;
}

int poly(int num, int stop) {
	stop ++;
	for(int i = stop - 2; stop > i; i++) if(i > 1) num *= i;
	return num;
}

float Trig::compute(float angle, int (Trig::*method)(int)) {
	float value = 0;
	float rad = this->deg_rad(angle);

	// cout << rad << endl;
	// cout << endl;
	int num = 1;
	int coeff = -1;
	for(int i = 0; i < 5; i++){ 
		int term = (this->*method)(i);
		// cout << term << " ";
		num = poly(num, term);
		// cout << num << endl;
		coeff *= -1;
		float expansion = coeff *  pow(rad, term) / num;
		value += expansion;
		// cout << value << endl;
	}

	return value;
}

