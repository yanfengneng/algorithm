#include <iostream>
#include <cstring>
using namespace std;

// ��������ַ���������ͻ��hash����

const int N = 1e5+10;
// ttʹ�ù���Щ�±꣬Ҫ����Ҫ��tt+1
int n,tt=0,p=99991;

// head��ŵ��ǹ�ϣֵ��next��ŵ���ͬһ����ϣֵ��Ӧ��һ��������±�
int snow[N][6],head[N],nxt[N];

// hash��������hashֵ��������״��ͬ��ѩ��������6���ߵĺ͡�������ȣ�������ǵ�hashֵҲ���
int H(int a[])
{
    int sum=0,mul=1;
    for(int i=0;i<6;++i)
    {
        sum=(sum+a[i])%p;
        mul=(long long)mul*a[i]%p;
    }
    return (sum+mul)%p;
}

// �ж���Ƭѩ���Ƿ����
bool equal(int a[],int b[])
{
    for(int i=0;i<6;++i)
        for(int j=0;j<6;++j)
        {
            bool eq=1;
            // ��Ƭѩ����ͬ��������෴�����ж���
            for(int k=0;k<6;++k)
                if(a[(i+k)%6]!=b[(j+k)%6])eq=0;
            if(eq)return 1;
            eq=1;
            for(int k=0;k<6;++k)
                if(a[(i+k)%6]!=b[(j-k+6)%6])eq=0;
            if(eq)return 1;
        }
    return 0;
}

bool insert(int a[])
{
    int val=H(a);
    // ������ͷhead[val]ָ���������Ѱ����״��ͬ��ѩ����0��ʾ��
    for(int i=head[val];i!=0;i=nxt[i])
        if(equal(snow[i],a))return 1;
    // δ�ҵ���״��ͬ��ѩ����ִ�в���
    ++tt;
    memcpy(snow[tt],a,6*sizeof(int));

    // �����ͷ�巨
    nxt[tt]=head[val];
    head[val]=tt;
    return 0;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int a[10];
        for(int i=0;i<6;++i)scanf("%d",&a[i]);
        if(insert(a))
        {
            puts("Twin snowflakes found.");
            return 0;
        }
    }
    puts("No two snowflakes are alike.");
    return 0;
}