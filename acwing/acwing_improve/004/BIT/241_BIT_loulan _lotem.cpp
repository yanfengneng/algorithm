#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 2e5+10;
int a[N],tree[N];// �����������״����
int Greater[N],Lower[N];// greater[i]=c��ʾ1~i-1����c�����Ǵ���yi�ģ�lower[i]=c��ʾ1~i-1����c������С��yi��
int n;

// ��״����3������Ĭд
// ���ض��������λ1��Ӧ��ʮ������
int lowbit(int x){
    return x&-x;
}

// ǰx�������ܺ�
int sum(int x)
{
    int res=0;
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
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);

    memset(tree,0,sizeof tree);
    // ��������ɨ��
    for(int i=1;i<=n;++i)
    {
        int y=a[i];
        // ai��ߣ�[y+1,n]���ж��ٸ����Ǵ���ai�ģ�[1,y-1]�ж��ٸ�����С��ai��
        Greater[i]=sum(n)-sum(y),Lower[i]=sum(y-1);
        // ÿ����һ�������Ͱ�ai���뵽������ȥ���൱����ai���λ����+1
        add(y,1);
    }

    memset(tree,0,sizeof tree);
    LL res1=0,res2=0;
    // ��������ɨ��
    for(int i=n;i;i--)
    {
        int y=a[i];
        // a[i]�ұߣ�[y+1,n]���ж��ٸ����Ǵ���ai�ģ�[1,y-1]�ж��ٸ�����С��ai��
        // �����������ΪV�͵�V��������
        res1+=Greater[i]*1LL*(sum(n)-sum(y));
        res2+=Lower[i]*1LL*sum(y-1);
        // ÿ����һ�������Ͱ�ai���뵽������ȥ���൱����ai���λ����+1
        add(y,1);
    }

    printf("%lld %lld\n",res1,res2);
    
    return 0;
}