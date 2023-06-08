#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

#define MAX_LEN 501
using namespace std;
map<string, bool> str_m;


int main()
{
    int n,m; scanf("%d %d", &n,&m);
    for(int i=0 ; i < n ; i++)
    {
        string str; cin >> str;
        str_m[str] = true;
    }
    int cnt = 0;
    for(int i=0 ; i < m ; i++)
    {
        string str; cin >> str;
        if(str_m[str]) cnt += 1;
    }
    printf("%d\n", cnt);
    return 0;
}