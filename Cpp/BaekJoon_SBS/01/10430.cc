#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >>b>>c;

    int result[4];
    result[0] = (a+b)%c;
    result[1] = ((a%c)+(b%c))%c;
    result[2] = (a*b)%c;
    result[3] = ((a%c)*(b%c))%c;

    for(int i = 0 ; i < 4 ; i ++) cout << result[i] << endl;
    return 0;
}