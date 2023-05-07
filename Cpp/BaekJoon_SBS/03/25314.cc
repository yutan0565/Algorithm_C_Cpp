#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int need_byte;
    need_byte = (n-1) /4 + 1;
    for(int i = 0 ; i < need_byte ; i++) cout << "long ";
    cout <<"int"<<endl;
    return 0;
}