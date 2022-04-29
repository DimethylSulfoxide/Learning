#include <iostream>
#include <fstream>
using namespace std;

int main(void){
	ofstream f("./s1.txt", ios::out);
	char t[20] = {'\0'};
	cout << "Enter a word:";
	cin >> t;
	f << t;
	f.close();
	t[0] = '\0';
	ifstream fin("./s1.txt", ios::in);
	fin >> t;
	fin.close();
	int d = 'D' - 'd';
	ofstream fout("./s2.txt", ios::out);
	for (int i = 0; t[i]; i ++)
		if (t[i] >= 'a' && t[i] <= 'z')
			t[i] += d;
	fout << t;
	fout.close();
	return 0;
}


