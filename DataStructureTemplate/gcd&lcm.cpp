#include <iostream>
using namespace std;

//辗转相除法求最大公约数
int gcd(int a,int b){
    if(!a||!b)return 0;
    while(b){//余数为0表示我们已经找到最大公约数了
        //每次相除保留除数和余数，即相除之后a为除数，b为余数，直到b为0为止
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

//最大公约数：两数之积除以两数的最大公约数
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