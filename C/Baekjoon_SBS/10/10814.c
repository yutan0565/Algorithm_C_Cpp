#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Info {
    int age;
    char name[201];
}info;

info info_table[100001];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %s", &info_table[i].age, info_table[i].name);
    }

    for (int i = 1; i <= 200; i++){
        for (int j = 0; j < n; j++){
            if (i == info_table[j].age)
                printf("%d %s\n", info_table[j].age, info_table[j].name);
        }
    }
}
