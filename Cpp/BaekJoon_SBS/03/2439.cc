#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int empty, star;
    for(int star=1 ; star< n + 1 ; star++)
    {
        empty = n - star;
        for(int j=0 ; j < empty ; j++) cout << " ";
        for(int j=0 ; j < star ; j++) cout << "*";
        cout << endl;
    }

    return 0;
}