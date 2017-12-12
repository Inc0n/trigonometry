#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

int poly(int stop) {
	int r_num = 1;
	stop ++;
	for(int i = 2; i < stop; i++) r_num *= i;
	return r_num;
}

float deg_rad(int degree) {
	return PI / (180 / 60);
}

int sine(int i) {
	return 2 * i + 1;
}

int cosine(int i) {
	return 2 * i;
}

float compute(float angle, int (*trig)(int)) {
	double value = 0;
	double rad = deg_rad(angle);
	
	for(int i = 0; i < 5; i++){ 
		int num = trig(i);
		double expansion = pow(-1, i) * pow(rad, num) / poly(num);
		value += expansion;
	}

	return value;
}

int main(int argc, char *argv[]){
	int angle = 60;
	cout << compute(angle, &sine) << endl;

}
