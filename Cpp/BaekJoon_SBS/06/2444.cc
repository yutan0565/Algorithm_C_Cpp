#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = n-1 ; i > 0 ; i--)
    {
        int empty = i;
        int star = 2*n-1-2*empty;
        for(int j = 0 ; j < empty ; j++) cout << " ";
        for(int j = 0 ; j < star ; j++) cout << "*";
        cout << endl;
    }

    for(int i = 0 ; i< 2*n-1 ; i++) cout << "*";
    cout << endl;

    for(int i = 1; i < n ; i++)
    {
        int empty = i;
        int star = 2*n-1-2*empty;
        for(int j = 0 ; j < empty ; j++) cout << " ";
        for(int j = 0 ; j < star ; j++) cout << "*";
        cout << endl;
    }


    return 0;
}