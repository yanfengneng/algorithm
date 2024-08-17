#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n;
// �������顢��״���顢�������
int h[N],tree[N],res[N];

// ��״������������Ĭд
int lowbit(int x)
{
    return x&-x;
}

void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=v;
}

int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=tree[i];
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;++i)scanf("%d",&h[i]);

    // ��״�����ʼ����ÿ��λ�õ�ʹ�ô���Ϊ1
    for(int i=1;i<=n;++i)add(i,1);

    // �Ӻ���ǰ��Ѱ�ҵ�kС����
    for(int i=n;i;i--)
    {
        int k=h[i]+1;// ��ʾh[i]��ʣ�������е�kС����
        // ����ǰ׺����Ѱ�ҵ�kС������sum(x)=k��ʾλ��xǡ��Ϊ��kС������λ��x֮ǰ��ǰ׺��С��k����λ��x��ǰ׺��ǡ��Ϊk����xΪ��kС����
        int l=1,r=n;
        while(l<r)
        {
            int mid=l+r>>1;
            if(sum(mid)>=k)r=mid;
            else l=mid+1;
        }
        // ����kС��λ������res��������λ��ʹ�ô���-1
        res[i]=l;
        add(l,-1);
    }
    for(int i=1;i<=n;++i)printf("%d\n",res[i]);
    return 0;
}