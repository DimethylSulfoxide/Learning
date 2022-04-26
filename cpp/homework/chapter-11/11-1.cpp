#include <iostream>
using namespace std;

class Rectangle{
	// todo
	private:
		double width;
		double length;
	public:
		Rectangle(){
			this->length = 0.;
			this->width = 0.;
		}
		void iptValue(){
			cout << "请输入矩形的长与宽（以空格分隔）:";
			cin >> this->length >> this->width;
		}
		double getArea(){
			return this->length * this->width;
		}
};

int main(void){
	Rectangle rect;
	rect.iptValue();
	cout << "矩形的面积是" << rect.getArea() << endl;
	return 0;
}
