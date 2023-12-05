#include <iostream>
using namespace std;

// 辗转相除法求最大公约数
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

// 最小公倍数：两数之积除以两数的最大公约数
int lcm(int a,int b){
    if(!a||!b)return 0;
    return a*b/gcd(a,b);
}

int main()
{
    cout<<gcd(319,377)<<endl;
    cout<<lcm(319,377)<<endl;
    system("pause");
}