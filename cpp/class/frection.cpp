#include <iostream>
#include <cmath>
using namespace std;

class Fraction{
	private:
		int up;
		int dn;
		char *str;
	public:
		Fraction();
		Fraction(int up, int dn);

		Fraction operator+(Fraction&);
		Fraction operator-(Fraction&);
		Fraction operator*(Fraction&);
		Fraction operator/(Fraction&);
		//void simplify();
		char *toStr();
		~Fraction();
	//
};

int main(void){
	//
	return 0;
}

Fraction::Fraction(){
	this->up = 0;
	this->dn = 114514;
	this->str = NULL;
}

Fraction::Fraction(int up, int dn){
	if (up * dn < 0){
		if (up < 0)
			;
		else {
			up = -up;
			dn = -dn;
		}
	}
	this->up = up;
	this->dn = dn;
	this->str = NULL;
}

Fraction Fraction::operator+(Fraction &a){
	this->up *= a.dn;
	a.up *= this->dn;
	this->dn = this->dn * a.dn;
	a.dn = this->dn;
	this->up += a.up;
	//this->simplify();
	//a.simplify();
	return Fraction(this->up, this->dn);

}

Fraction Fraction::operator-(Fraction &a){
	a.up = -a.up;
	Fraction t = Fraction(this->up, this->dn);
	return t + a;
}

Fraction::~Fraction()
{
}
