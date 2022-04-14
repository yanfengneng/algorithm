#include <iostream>
using namespace std;

const int N=1000010;

// cnt��ʾ��������
int primes[N],cnt=0;
bool st[N];

// ��������ɸ��
void get_primes(int n)
{
    for(int i=2;i<=n;++i)
    {
        // i����������ô���������������
        if(!st[i])primes[cnt++]=i;
        // ����ǰ��i����һ��������
        for(int j=0;primes[j]*i<=n;j++)
        {
            // ���Ϊ����
            st[primes[j]*i]=true;
            // i�б�prime[j]��С��������
            if(i%primes[j]==0)break;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    get_primes(n);
    for(int i=0;i<cnt;++i)
    {
        int p=primes[i];

        int s=0,t=n;
        //�������N!��������p�ĸ�����ÿ��ѭ��t/p��ʾ�´�ѭ��p�Ĵ���+1
        while(t)s+=t/p,t/=p;
        printf("%d %d\n",p,s);
    }
    return 0;
}