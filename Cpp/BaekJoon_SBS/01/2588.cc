#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    int result1, result2, result3, result4;
    result1 = a * (b%10);
    result2 = a * ((b/10)%10);
    result3 = a * ((b/100)%10);
    result4 = a * b;

    cout << result1<<endl;
    cout << result2<<endl;
    cout << result3<<endl;
    cout << result4<<endl;
    return 0;
}