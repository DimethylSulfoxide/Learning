#include <iostream>
using namespace std;

class test{
	private:
		int a;
	public:
		test(int a){
			this->a = a;
		}
		void p(test &a){
			a.a = -a.a;
			cout << a.a << endl;

		}
};

int main(void){
	test a = test(1);
	test b = test(2);
	a.p(b);
	return 0;
}
