#include <iostream>

using namespace std;

int main()
{
    int h,s;
    cin>>h>>s;
    int gap;
    cin>>gap;

    int total_s = (60*h + s + gap)%(24*60);
    cout << (total_s/60) <<" "<<(total_s%60);

    return 0;
}