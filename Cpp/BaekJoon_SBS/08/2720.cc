#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define endl '\n'
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0 ; i<t ; i++)
    {
        int num; cin >> num;
        num *= 10;
        cout << num/250 << " ";
        num %= 250;
        cout << num/100 << " ";
        num %= 100;
        cout << num/50 << " ";
        num %= 50;
        cout << num/10 << " ";
        num %= 10;
        cout << endl;
    }

    return 0;
}