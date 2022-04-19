//请在此添加代码，实现书籍数据的输入、排序和输出
/********** Begin *********/
#include <iostream>
using namespace std;

struct b{
    char n[50];
    double p;
};

int main(void){
    b bk[100], t;
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i ++){
        cin.getline(bk[i].n, 50);
        //gets(bk[i].n)
        // fgets(bk[i].n, 50, stdin);
        cin >> bk[i].p;
        //cin >> bk[i].n >> bk[i].p;
	getchar();
    }
    for (int i  = 0; i < n; i ++)
        for (int j = 0; j < n - i - 1; j ++){
            if (bk[j].p > bk[j+1].p){
                t = bk[j];
                bk[j] = bk[j+1];
                bk[j+1] = t;
            }
        }
    
    for (int i = 0; i < n; i ++)
        cout << bk[i].p << ", " << bk[i].n << '\n';
    
    return 0;
}

/********** End **********/


