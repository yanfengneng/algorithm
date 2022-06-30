#include <iostream>
using namespace std;

const int N = 1e6+10;
// primes�����������������cnt��ʾ��������  
int primes[N],cnt=0;
// ����Ǻ�������������0Ϊ������1Ϊ����
bool flag[N];

// ��������ɸ������ÿ������ֻ�ᱻ������С������ɸһ��
void get_primes(int n)
{
    for(int i=2;i<=n;++i)
    {
        // iΪ�����������primes��
        if(!flag[i])primes[cnt++]=i;

        // ����ǰ��i����һ��������pj
        for(int j=0;primes[j]<=n/i;++j)
        {
            // ������һ������x����pj��x����С�����ӣ���i<x/pjʱ��һ���ᱻɸ��
            flag[i*primes[j]]=1;
            /*
                i%pj==0����ʾpjһ����i����С�����ӣ���Ϊ��������С����ö�������ӵģ���ôpjһ����pj*i����С�����ӣ�֮���pj+1,pj+2...֮���
                �����ӾͲ���p[j+x] *i ����С���������ˣ���Ϊp[j+x] *i ����С������Ϊi����С������pj�����������ǰ���С�����ӽ���ɸѡ�ģ�����
                p[j+x] *i ֮ǰ�϶�����������С������pj�Ѿ�ɸ�ˣ����Ǽ���ɸ�Ļ����ض����ظ��ġ�

                i%pj!=0����ʾpj��i�����������Ӷ�ҪС����Ϊi���������Ǳض���������i�ģ���i%pj!=0����ʾpj��i�����������Ӷ�ҪС����������ɸ
                i*pj������С������pjɸ�ģ�Ȼ��������ö��pj+1,pj+2������i������һ����С�����ӣ����Բ���break��

                �ܽ�һ�仰������ɸֻ������С�����ӽ���ɸѡ
            */
            if(i%primes[j]==0)break;
        }
    }
}

// ŷ��ɸѡ
bool v[N];
void oula_primes(int n)
{
    memset(v,0,sizeof v);
    int m=0;
    for(int i=2;i<=n;++i)
    {
        if(v[i])continue;
        m++;
        for(int j=2*i;j<=n;j+=i)v[j]=1;
    }
    cout<<m<<endl;
}

int main()
{
    int n;
    scanf("%d",&n);
    get_primes(n);
    printf("%d\n",cnt);
    return 0;
}