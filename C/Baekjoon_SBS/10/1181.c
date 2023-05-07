#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word{
    char string[51];
    int len;
}word;

int compare(const void *first, const void *secode){
    word s1 = *(word*)first, s2 = *(word*)secode;
    if (s1.len < s2.len)
        return -1;
    else if (s1.len > s2.len)
        return 1;
    return strcmp(s1.string, s2.string);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    word w_list[n];
    for(i = 0 ; i < n ; i++){
        scanf("%s", w_list[i].string);
        w_list[i].len = strlen(w_list[i].string);
    }   

    qsort(w_list, n, sizeof(word), compare);
    puts(w_list[0].string);
    for (int i = 1; i < n; i++)
        if (strcmp(w_list[i-1].string, w_list[i].string))
            puts(w_list[i].string);
    return 0;
}

