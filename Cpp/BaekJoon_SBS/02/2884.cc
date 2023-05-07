#include <iostream>

using namespace std;

int main()
{
    int h,s;
    cin >>h>>s;

    int total_s;
    total_s = h*60 + s - 45;

    if(total_s < 0) cout << 23 <<" "<< (60+total_s);  
    else cout << (total_s/60) <<" "<< (total_s%60);   
    return 0;
}