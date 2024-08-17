#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1e5+10;
int a[N];
// ��״������ܻᱬint������Ҫ�� long long ����
LL tree[N];
int n,m;

// ����Ϊ��״��������������Ĭд
int lowbit(int x)
{
    return x&-x;
}

// ��x��������
LL sum(int x)
{
    LL res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=tree[i];
    return res;
}

// ��λ��x�ϼ���v
void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=v;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);

    // ��ԭ����ת��Ϊ������飬����������ӷ�ת��Ϊ��ӷ������x������ֵת��Ϊǰ׺��
    // a[l,r]+c => b[l]+c b[r+1]-c��a[x]=b[1]+b[2]+...+b[x]=a[1]+a[2]-a[1]+...+a[x]-a[x-1]=a[x]
    for(int i=1;i<n;++i)add(i,a[i]-a[i-1]);

    while(m--)
    {
        char op[2];
        int l,r,d;
        // ʹ��%s���Զ����˵��ո�ͻس�
        scanf("%s%d",op,&l);
        if(*op=='C')
        {
            scanf("%d%d",&r,&d);
            // ������齫ԭ���������ӷ�ת��Ϊ��ӷ�
            add(l,d),add(r+1,-d);
        }
        else{
            // ������齫���x����ת��Ϊǰ׺��
            printf("%lld\n",sum(l));
        }
    }
    return 0;
}