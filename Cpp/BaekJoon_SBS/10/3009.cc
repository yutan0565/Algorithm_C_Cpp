#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> x_v;
vector<int> y_v;

int main()
{
    for(int i=0; i < 3 ; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        x_v.push_back(a);
        y_v.push_back(b);
    }

    if (x_v[0] == x_v[1]) x_v[3] = x_v[2];
	else if (x_v[0] == x_v[2]) x_v[3] = x_v[1];
	else x_v[3] = x_v[0];

	if (y_v[0] == y_v[1]) y_v[3] = y_v[2];
	else if (y_v[0] == y_v[2]) y_v[3] = y_v[1];
	else y_v[3] = y_v[0];
 
	printf("%d %d", x_v[3], y_v[3]);
    return 0;
}
