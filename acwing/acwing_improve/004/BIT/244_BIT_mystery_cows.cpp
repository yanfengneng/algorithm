#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n;
// 输入数组、树状数组、结果数组
int h[N],tree[N],res[N];

// 树状数组三个函数默写
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

    // 树状数组初始化：每个位置的使用次数为1
    for(int i=1;i<=n;++i)add(i,1);

    // 从后往前来寻找第k小的数
    for(int i=n;i;i--)
    {
        int k=h[i]+1;// 表示h[i]在剩余数组中第k小的数
        // 利用前缀和来寻找第k小的数，sum(x)=k表示位置x恰好为第k小的数，位置x之前的前缀和小于k，在位置x上前缀和恰好为k，则x为第k小的数
        int l=1,r=n;
        while(l<r)
        {
            int mid=l+r>>1;
            if(sum(mid)>=k)r=mid;
            else l=mid+1;
        }
        // 将第k小的位置添入res，并将该位置使用次数-1
        res[i]=l;
        add(l,-1);
    }
    for(int i=1;i<=n;++i)printf("%d\n",res[i]);
    return 0;
}