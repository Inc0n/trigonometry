#include <iostream>
#include <cmath>
#include <sstream>
#include "trig.h"
// #include <iomanip> 

#define PI 3.14159265358979323846

using namespace std;

int poly(int stop) {
	int r_num = 1;
	stop ++;
	for(int i = 2; i < stop; i++) r_num *= i;
	return r_num;
}

float deg_rad(int degree) {
	return PI / (180.0 / degree);
}

int sine(int i) {
	return 2 * i + 1;
}

int cosine(int i) {
	return 2 * i;
}

float compute(float angle, int (*trig)(int)) {
	float value = 0;
	float rad = deg_rad(angle);
	// cout << rad << endl;
	// cout << endl;

	for(int i = 0; i < 5; i++){ 
		int num = trig(i);
		// cout << num << endl;
		float expansion = pow(-1, i) * pow(rad, num) / poly(num);
		// cout << poly(num) << endl;
		cout << pow(rad, num) << endl;
		value += expansion;
		// cout << value << endl;
	}

	return value;
}

float tan(int angle) {
	return compute(angle, &sine) / compute(angle, &cosine);
}

bool toInt(string str, int &value) {
	istringstream iss(str);
	
	if (!iss.fail())
    {
       if (iss >> value)
           return true;

       iss.clear();
       iss.ignore();
    }
    return false; // There is no integer!
}

int main(int argc, char *argv[]){

	int angle;
	if (argc > 1) {
		if (!toInt(argv[1], angle))
			return -1;
	}
	// cout << compute(30, &sine) << endl;
	// cout << tan(angle) << endl;

	Trig test;
	float result = test.cosine(29);
	cout << result << endl;
	return 0;
}
