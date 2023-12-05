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
        // �������ֽ�
        for(int i=2;i<=x/i;++i)
        {
            // x�ɱ�i�ֽ⣬���i��ָ��
            while(x%i==0)
            {
                primes[i]++;
                x/=i;
            }
        }
        // x����һ������sqrt(x)��������
        if(x>1)primes[x]++;
    }

    LL res=1;
    for(auto prime:primes)
    {
        // p Ϊ������a Ϊָ��
        int p=prime.first,a=prime.second;
        LL t=1;
        // ��p^0+p^1+...+p^a����Լ����һ�����š���һ��Ϊp+1���ڶ���Ϊp*(p+1)+1=p^2+p+1...��a��Ϊp^a+p^(a-1)+...+1
        while(a--)t=(p*t+1)%mod;
        // (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
        res=res*t%mod;
    }
    cout<<res<<endl;
    return 0;
}