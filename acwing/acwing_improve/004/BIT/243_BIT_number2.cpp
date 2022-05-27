#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1e5+10;
int n,m;
// 输入数组
int a[N];
// tree1[i]存储差分数组b[i]；tree2[i]存储i*b[i]
LL tree1[N],tree2[N];

int lowbit(int x)
{
    return x&-x;
}

// 求前x项的总和
LL sum(LL tree[],int x)
{
    LL res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=tree[i];
    return res;
}

// 在第x个位置加上v，v必须要用LL 防止爆int
void add(LL tree[],int x,LL v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=v;
}

// 求前缀和
LL prefix_sum(int x)
{
    return sum(tree1,x)*(x+1)-sum(tree2,x);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);

    for(int i=1;i<=n;++i)
    {
        // 差分数组
        int b=a[i]-a[i-1];
        // a[l,r]区间加法变成点加法b[l]+=c,b[r+1]-=c
        add(tree1,i,b);
        // 区间和变成点和，a[l...r]=b[1...l]+b[1...(l+1)]+...b[1...r]=(x+1)*b[1...x]-(b1*1+b2*2+...+bx*x)
        add(tree2,i,1LL*i*b);
    }

    while(m--)
    {
        char op[2];
        int l,r,d;
        scanf("%s%d%d",op,&l,&r);
        if(*op=='C')
        {
            scanf("%d",&d);
            // b[l]+=d
            add(tree1,l,d),add(tree2,l,1LL*l*d);
            // b[r+1]-=d
            add(tree1,r+1,-d),add(tree2,r+1,(r+1)*-d);
        }
        else{
            printf("%lld\n", prefix_sum(r)-prefix_sum(l - 1));
        }
    }
    return 0;
}