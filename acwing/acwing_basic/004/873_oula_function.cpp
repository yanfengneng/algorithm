#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    while(n--)
    {
        int a;cin>>a;
        int res=a;
        // 以下就是分解质因数的模板了，利用公式求欧拉函数
        for(int i=2;i<=a/i;++i)
        {
            if(a%i==0)// a可以被质因子i整除，则把i的所有次数都除尽即可
            {
                // 其中i为底数，将(1-1/i)会产生小数，因此变形为(i-1)/i
                res=res/i*(i-1);
                while(a%i==0)a/=i;
            }
        }
        // a最多会包含一个大于sqrt(a)的质因子，最后a>1表示存在这个质因子了，需要进行计算
        if(a>1)res=res/a*(a-1);
        cout<<res<<endl;
    }
    return 0;
}