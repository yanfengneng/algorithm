#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;
const int mod = 1e9+7;

int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> primes;
    while(n--)
    {
        int x;
        cin>>x;
        // 质因数分解
        for(int i=2;i<=x/i;++i)
        {
            // x可被i分解，则就i的指数
            while(x%i==0)
            {
                primes[i]++;
                x/=i;
            }
        }
        // x还有一个大于sqrt(x)的质因子
        if(x>1)primes[x]++;
    }

    LL res=1;
    for(auto prime:primes)
    {
        // p 为底数，a 为指数
        int p=prime.first,a=prime.second;
        LL t=1;
        // 算p^0+p^1+...+p^a，即约数的一个括号。第一项为p+1，第二项为p*(p+1)+1=p^2+p+1...第a项为p^a+p^(a-1)+...+1
        while(a--)t=(p*t+1)%mod;
        // (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
        res=res*t%mod;
    }
    cout<<res<<endl;
    return 0;
}