#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

#define endl '\n'
using namespace std;
int t; 

int gcd(int a, int b){
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    scanf("%d", &t);
    while(t--)
    {   
        int a,b;
        scanf("%d %d", &a,&b);
        int max_num = a*b / gcd(a,b);
        cout << max_num << endl;
    }

    return 0;
}