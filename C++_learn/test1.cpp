/* 1-1 .cpp*/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int num[8];
    memset(num,1,32);
    for (int i = 0;i<8;i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}
