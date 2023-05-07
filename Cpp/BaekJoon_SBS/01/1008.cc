#include <iostream>

using namespace std;

double devide_num(int a, int b)
{
    double result;
    result = (double)a / (double)b;
    return result;
}

int main()
{
    int a,b;
    cin >> a >> b;

    double result;
    result = devide_num(a,b);
    cout.precision(12);
    cout << result;

    return 0;
}

