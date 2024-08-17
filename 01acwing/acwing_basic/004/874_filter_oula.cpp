#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// ����ɸ����ŷ������
const int N = 1e6+10;
int primes[N],cnt=0;
bool st[N];// ����Ǻ�������������0Ϊ������1Ϊ����
int phi[N];

LL get_eulers(int n)
{
    // ���ݶ��妷(1)=1
    phi[1]=1;
    // ��ʼ��������ɸ����ŷ������
    for(int i=2;i<=n;++i)
    {
        // iΪ������洢����������primes��
        if(!st[i])
        {
            primes[cnt++]=i;
            // �����Ǹ���ŷ����������Ķ�������õ��ģ���1~N����N���ʵ����ĸ�����Ϊŷ������
            // ��Ȼһ������p��p-1�������以�ʣ�Ҳ����1~(1-p)���Ǻ�p�ǻ��ʵ�
            phi[i]=i-1;
        }
        // ����ǰ��i����һ��������pj
        for(int j=0;primes[j]<=n/i;++j)
        {
            // ������һ������x����pj��x����С�����ӣ���i<x/pjʱ��һ���ᱻɸ��
            st[i*primes[j]]=1;
            // ��i%primes[j]==0ʱ��������С�����ӽ���ɸѡ
            if(i%primes[j]==0)
            {
                /*
                ����������ŷ�����������������Ƴ��Ĺ�ʽ��
                    phi(i*pj)=i*pj*(1-p1)*...*(1-pk)=pj*phi(i)
                    i*pj��i�����һ��pj����ôpj*i�ֽ�֮���������������ֻ�Ǳ�i����һ��pj���ѣ�����pj��i��һ�������ӣ�����i*pj�����������Ӷ���i�г��ֹ��ˣ�����ǰ����������һ��pj�����ϼ���
                */
                phi[i*primes[j]]=phi[i]*primes[j];
                break;
            }
            // ��i%primes[j]!=0ʱ����ôpjһ����i*pj����С�����ӣ�����pjû�б�������i�������ӵ��У�����phi(i*pj)=i*pj*(1-1/p1)*...*(1-1/pk)*(1-1/pj)=pj*(1-1/pj)*phi(i)=(pj-1)*phi(i)
            phi[i*primes[j]]=phi[i]*(primes[j]-1);
        }
    }

    LL res=0;
    for(int i=1;i<=n;++i)res+=phi[i];
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",get_eulers(n));
    return 0;
}
