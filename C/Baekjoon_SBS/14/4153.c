#include <stdio.h>
#include <math.h>

void swap(int f_idx, int s_idx, int list[]){
    int temp = list[f_idx];
    list[f_idx] = list[s_idx];
    list[s_idx] = temp;
}

void max_swap(int list[]){
    if(list[0]  < list[1]) swap(0,1,list);
    if(list[1]  < list[2]) swap(1,2,list);
    if(list[0]  < list[1]) swap(0,1,list);
}

int main(void){
    int p_list[3];
    while(1){
        scanf("%d %d %d", &p_list[0], &p_list[1], &p_list[2]);
        if(p_list[0] == 0 && p_list[1] == 0 && p_list[2] == 0) break;
        max_swap(p_list);
        if(pow(p_list[0], 2) == (pow(p_list[1], 2) + pow(p_list[2], 2))) printf("right\n");
        else printf("wrong\n");

    }

}
