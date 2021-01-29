#include <iostream>
using namespace std;

// 欧几里算法求最大公约数
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}