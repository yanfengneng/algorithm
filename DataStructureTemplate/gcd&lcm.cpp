#include <iostream>
using namespace std;

// շת����������Լ��
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

// ��С������������֮���������������Լ��
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