#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=1000010;

// primes�������������cnt����ͳ�������ĸ���
// st����������������Ǻ�����0��ʾ������1��ʾ����
int primes[N],cnt=0;
bool st[N];

// ��������ɸ��
void get_primes(int n)
{
    // ������lr�����ÿ�ζ�Ҫ���¼�������
    memset(st,false,sizeof st);
    cnt=0;
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
    long long l,r;
    while(cin>>l>>r)
    {
        // һ������N�ض�����һ��������sqrt(N)�������ӣ�sqrt(2^31-1)=4w��~~=5w
        get_primes(50000);

        //������50000�ڵ���������֮���ڽ�st��ԭ����[2,sqrt(r)]�ڵ�����p�ı������Ϊ����
        memset(st,false,sizeof st);
        for(int i=0;i<cnt;++i)
        {
            int p=primes[i];
            
            // ����pΪ���������ǽ�p�ı���ɸ������������ֻ�ܴ�2p��i*p�ϴ�ֵ��ʼɸ
            // p�ı���Ϊ��������ɸ��������
            for(long long j=max((l+p-1)/p*p,2ll*p);j<=r;j+=p)
            {
                st[j-l]=true;// j-l��Ϊ�˱��ں�������ͳ��[l,r]�ڵ�����
            }
        }

        // ����ɸ����[r,l]�ڵĺ���������Ҫ���¼���÷�Χ�ڵ�����
        cnt=0;
        for(int i=0;i<=r-l;++i)
            if(!st[i]&&i+l>1)// 1Ҫ���⴦���£���Ϊ1��������Ҳ���Ǻ���
                primes[cnt++]=i+l;// iҪ����ƫ����l����Ϊǰ�����ƫ����l
        
        if(cnt<2) puts("There are no adjacent primes.");
        else
        {
            int minP=0,maxP=0;
            // ʹ��i+1��Ϊ�˷�ֹ����������±�Խ��
            for(int i=0;i+1<cnt;++i)
            {
                int d=primes[i+1]-primes[i];
                // ��������������Զ����
                if(d<primes[minP+1]-primes[minP])minP=i;
                if(d>primes[maxP+1]-primes[maxP])maxP=i;
            }

            printf("%d,%d are closest, %d,%d are most distant.\n", primes[minP], primes[minP + 1], primes[maxP], primes[maxP + 1]);
        }
        
    }
}