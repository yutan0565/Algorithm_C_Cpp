#include <iostream>

using namespace std;

int main()
{
    int x,n,a,b,total = 0;
    cin >> x;
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >>a>>b;
        total += (a*b);
    }

    if(total == x) cout << "Yes";
    else cout << "No";

    return 0;
}