#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1e5+10;
int a[N];
// 树状数组可能会爆int，所以要用 long long 来存
LL tree[N];
int n,m;

// 以下为树状数组三个函数的默写
int lowbit(int x)
{
    return x&-x;
}

// 求x项的数组和
LL sum(int x)
{
    LL res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=tree[i];
    return res;
}

// 在位置x上加上v
void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=v;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);

    // 将原数组转换为差分数组，这样将区间加法转换为点加法；求第x个数的值转换为前缀和
    // a[l,r]+c => b[l]+c b[r+1]-c；a[x]=b[1]+b[2]+...+b[x]=a[1]+a[2]-a[1]+...+a[x]-a[x-1]=a[x]
    for(int i=1;i<n;++i)add(i,a[i]-a[i-1]);

    while(m--)
    {
        char op[2];
        int l,r,d;
        // 使用%s来自动过滤掉空格和回车
        scanf("%s%d",op,&l);
        if(*op=='C')
        {
            scanf("%d%d",&r,&d);
            // 差分数组将原数组的区间加法转换为点加法
            add(l,d),add(r+1,-d);
        }
        else{
            // 差分数组将求第x个数转换为前缀和
            printf("%lld\n",sum(l));
        }
    }
    return 0;
}