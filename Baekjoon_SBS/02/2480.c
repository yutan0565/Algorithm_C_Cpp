#include <stdio.h>

int find_max(int a, int b, int c){
    int max_number = 0 ;
    int n_list[3] = {a,b,c};
    int i;
    for(i = 0 ; i < 3 ; i++){
        if (n_list[i] > max_number){
            max_number = n_list[i];
        }
    }
    return max_number;
}


int main(void){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    int total;
    if(a == b && b == c){
        total = 10000 + a *1000;
    }else if( a == b && c != b){
        total = 1000 + a * 100;
    }else if( a == c && b != a){
        total = 1000 + a * 100;
    }else if( c == b && a != b){
        total = 1000 + c * 100;
    }else{
        total = find_max(a,b,c) * 100;
    }
    printf("%d", total);

}