#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl '\n'
using namespace std;

int main()
{
    int n; cin >> n;
    int count = 2;
    for(int i = 0 ; i<n; i++)
    {
        count  = count + (count - 1);
    }
    int result = pow(count,2);
    cout << result << endl;
    return 0;
}