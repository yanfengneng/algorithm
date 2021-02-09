#include <iostream>
using namespace std;

const int N = 1e4+10;

int primes[N],cnt=0;    // ���������������
bool flag[N];           // ���������i�Ǻ�������������1Ϊ������0Ϊ����

// ����ɸ��������ɸ
void get_primes(int n)
{
    for(int i=2;i<=n;++i)
    {   
        // i Ϊ��������б��
        if(!flag[i])primes[cnt++]=i;

        // ����ǰ��i����һ����С������pj
        for(int j=0;primes[j]<=n/i;j++)
        {
            flag[i*primes[j]]=1;
            // ��ʱ�� pj Ϊ pj*i ����С�������ˣ����ǲ�Ҫ�������������ɸѡ i �ı����ˣ���Ϊ������ȥ���ظ�ɸѡ�ģ����break
            if(i%primes[j]==0)break;
        }
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    get_primes(10005);
    int res=0;
    for(int i=a;i<=b;++i)
    {
        if(i==1||flag[i])continue;
        int x=0,y=i;
        while(y)
        {
            x=x*10+y%10;
            y/=10;
        }
        if(flag[x])continue;
        res++;
    }
    cout<<res<<endl;
    return 0;
}