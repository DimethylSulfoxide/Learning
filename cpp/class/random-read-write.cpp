#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    char name[20];
    int grade;
};

int main(void){
    ofstream fout("./studata.dat", ios::out);
    student t;
    for (int i = 0; i < 5; i ++){
        cin >> t.name;
        cin >> t.grade;
        fout.write((char *)&t, sizeof(t));
    }
    fout.close();

    ifstream fin("./studata.dat", ios::in);
    for (int i = 0; i < 5; i += 2){
        fin.seekg(sizeof(t) * i, ios::beg);
        fin.read((char *)&t, sizeof(t));
        cout << "第" << i + 1 << "个学生:" << t.name << '\t' << t.grade << '\n';
    }
    fin.close();
    return 0;
}