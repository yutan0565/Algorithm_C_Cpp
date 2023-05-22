#include <iostream>

#define endl '\n'
using namespace std;

int main()
{
    int a,b,v; cin >> a >> b >> v;

    int day_up = a - b;
    int result = (v - b -1 ) / day_up + 1;
    cout << result;

    return 0;
}