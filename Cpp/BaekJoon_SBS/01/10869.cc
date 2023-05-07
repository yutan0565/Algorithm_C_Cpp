#include <iostream>

using namespace std;

int add_num(int a, int b)
{
    int result;
    result = a + b;
    return result;
}

int sub_num(int a, int b)
{
    int result;
    result = a- b;
    return result;
}

int mul_num(int a, int b)
{
    int result;
    result = a * b;
    return result;
}

int quo_num(int a, int b)
{
    int result;
    result = a / b;
    return result;
}

int remain_num(int a, int b)
{
    int result;
    result = a %b;
    return result;
}

int main()
{
    int a,b;
    cin >> a >> b;

    int result[5];
    result[0] = add_num(a,b);
    result[1] = sub_num(a,b);
    result[2] = mul_num(a,b);
    result[3] = quo_num(a,b);
    result[4] = remain_num(a,b);

    for(int i=0; i < 5 ; i++) cout << result[i]<<endl;
    return 0;
}