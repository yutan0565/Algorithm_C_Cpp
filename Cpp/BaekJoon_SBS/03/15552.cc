#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);

    int t;
    cin >> t;

    int a,b;
    for(int i = 0 ; i < t ; i++)
    {   
        cin >> a>> b;
        cout << (a+b) << "\n";
    }

    return 0;
}