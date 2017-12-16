#include <iostream>
#include <cmath>
#include <sstream>
#include "trig.h"
// #include <iomanip> 

using namespace std;

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
	if (argc == 1) {
		cout << "NEED ANGLE" << endl;
		return -1;
	}

	bool cosine;
	bool has_angle;
	bool sine = has_angle = cosine = false;

	argc --;
	for (; argc > 0; argc --) {
		if (strcmp(argv[argc],"-s") == 0) {
			sine = true;
		} else if (strcmp(argv[argc], "-c") == 0) {
			cosine = true;
		} else {
			has_angle = toInt(argv[argc], angle); 
		}
	}

	if (!has_angle) {
		return 2;
	} 
	Trig test;
	
	if (sine) {
		cout << test.sine(angle) << endl;
	} else if (cosine) {
		cout << test.cosine(angle) << endl;		
	}
	return 0;
}
