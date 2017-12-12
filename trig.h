
#define PI 3.14159265358979323846

class Trig {
public:
	double sine(float agnle);
	double cosine(float angle);
	double tan(float angle);

private:
	float compute(float angle, int (Trig::*method)(int));
	float deg_rad(int degree);
	// float pow(float base, int index);
	int m_sine(int i);
	int m_cosine(int i);

};