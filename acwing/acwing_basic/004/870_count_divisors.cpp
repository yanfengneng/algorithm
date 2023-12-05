#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9+7;
typedef long long LL;

int main()
{
    int n;
    cin>>n;
    // 用于记录 质因子->该质因子的个数
    unordered_map<int,int> primes;
    while(n--)
    {
        int x;
        cin>>x;
        // 质因数分解
        for(int i=2;i<=x/i;++i)
        {
            // 若x可被i进行分解的话，则统计i的次数，即i的指数
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
    // 约数个数为(a1+1)*(a2+1)*...*(ak+1)
    for(auto prime:primes)res=res*(prime.second+1)%mod;
    cout<<res<<endl;
    return 0;
}