#include <iostream>
using namespace std;

/*
欧几里算法求最大公约数
    当b=0时：a和0的最大公约数一定是a
    当b!=0时：(a,b)的最大公约数就与(b,a%b)的最大公约数，即gcd(a,b)=gcd(b,a%b)，证明如下：
    设公约数为d，
    1）左边推右边：若d能整除a即d|a，d能整除b即d|b，那么a÷b的余数r=a-c*b（其中c为商），则d也是能整除(a-c*b)=a%b的；左边推右边成立。
    2）右边推左边：若d能整除b即d|b，d能整除a-b*c即d|(a-b*c)，那么d也能整除(a-b*c+b*c) 这里加上b的倍数，最后结果还是可以整除的，消除同类项后得到d|a；右边推左边成立。
*/
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