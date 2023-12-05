#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9+7;
typedef long long LL;

int main()
{
    int n;
    cin>>n;
    // ���ڼ�¼ ������->�������ӵĸ���
    unordered_map<int,int> primes;
    while(n--)
    {
        int x;
        cin>>x;
        // �������ֽ�
        for(int i=2;i<=x/i;++i)
        {
            // ��x�ɱ�i���зֽ�Ļ�����ͳ��i�Ĵ�������i��ָ��
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
    // Լ������Ϊ(a1+1)*(a2+1)*...*(ak+1)
    for(auto prime:primes)res=res*(prime.second+1)%mod;
    cout<<res<<endl;
    return 0;
}