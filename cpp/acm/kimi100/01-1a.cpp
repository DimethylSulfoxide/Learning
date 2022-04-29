// 01-1a
#include <cstdio>

int main(void){
    char t[3], tmp = '\0';
    while (~scanf("%c%c%c%*c", t, t + 1, t + 2)){
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3 - 1 - i; j ++)
                if (t[j] > t[j+1]){
                    tmp = t[j];
                    t[j] = t[j+1];
                    t[j+1] = tmp;
                }
        printf("%c %c %c\n", t[0], t[1], t[2]);
    }
    return 0;
}