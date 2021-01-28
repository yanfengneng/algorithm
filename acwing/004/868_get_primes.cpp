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
                i%pj==0����ʾpjһ����i����С�����ӣ���Ϊ��������С����ö�������ӵģ���ôpjһ����pj*i����С������
                i%pj!=0����ʾpj��i�����������Ӷ�ҪС����ôpj*i����С������Ҳ����pj��
                ����ΪʲôҪbreak����Ϊ��ö����ȥ�Ļ���pj*i��������pj������С�������ˣ�������ɸ������������С�����ӽ���ɸѡ��
            */
            if(i%primes[j]==0)break;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    get_primes(n);
    printf("%d\n",cnt);
    return 0;
}