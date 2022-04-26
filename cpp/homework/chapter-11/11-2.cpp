#include <iostream>
#include <cmath>
using namespace std;

class Rational{
	private:
		int num;
		int den;
		void simplify();
	public:
		int getNum();
		int getDen();
		Rational add(Rational);
		Rational sub(Rational);
		void printReal();
		void printRati();
		Rational();
		Rational(int, int);
};

void Rational::simplify(){
	int a = abs(this->num), b = this->den;
	while (a != b){
		if (a > b)
			a = a - b;
		else 
			b = b - a;
	}
	this->num /= a;
	this->den /= a;
	return;

}

Rational::Rational(){
	int a, b;
	while (1){
		cout << "请输入分子:";
		cin >> a;
		cout << "请输入分母:";
		cin >> b;
		if (!b){
			cout << "分母不能为0.请重新输入.\n";
			continue;
		}
		else 
			break;
	}
	this->num = abs(a);
	this->den = abs(b);
	if (a * b < 0)
		this->num = -this->num;
	this->simplify();
	return;
}

Rational::Rational(int a, int b){
	this->num = a;
	this->den = b;
	this->simplify();
	return;
}

void Rational::printRati(){
	if (this->den == 1)
		cout << this->num;
	else 
		cout << this->num << "/" << this->den;
	return;
}

void Rational::printReal(){
	cout << 1.0 * this->num / this->den;
}

int Rational::getDen(){
	return this->den;
}

int Rational::getNum(){
	return this->num;
}

Rational Rational::add(Rational a){
	int x = this->num, y = this->den;
	x = a.getDen() * this->getNum() + a.getNum() * this->getDen();
	y *= a.getDen();
	return Rational(x, y);
}

Rational Rational::sub(Rational a){
	int x = this->num, y = this->den;
	x = a.getDen() * this->getNum() - a.getNum() * this->getDen();
	y *= a.getDen();
	return Rational(x, y);
}

int main(void){
	Rational a, b;
	cout << "分数a是:";
	a.printRati();
	cout << ", 即"; 
	a.printReal();
	cout << '\n';
	cout << "分数b是:";
	b.printRati();
	cout << ", 即"; 
	b.printReal();
	cout << '\n';

	Rational c = a.add(b);
	Rational d = a.sub(b);
	cout << "a + b = ";
	c.printRati();
	cout << ", 即";
	c.printReal();
	cout << '\n';
	cout << "a - b = ";
	d.printRati();
	cout << ", 即";
	d.printReal();
	cout << '\n';


	return 0;
}
