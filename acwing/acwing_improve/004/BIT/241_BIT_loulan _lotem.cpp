#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 2e5+10;
int a[N],tree[N];// 输入数组和树状数组
int Greater[N],Lower[N];// greater[i]=c表示1~i-1中有c个数是大于yi的，lower[i]=c表示1~i-1中有c个数是小于yi的
int n;

// 树状数组3个函数默写
// 返回二进制最低位1对应的十进制数
int lowbit(int x){
    return x&-x;
}

// 前x项数的总和
int sum(int x)
{
    int res=0;
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
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);

    memset(tree,0,sizeof tree);
    // 从左向右扫描
    for(int i=1;i<=n;++i)
    {
        int y=a[i];
        // ai左边：[y+1,n]中有多少个数是大于ai的，[1,y-1]中多少个数是小于ai的
        Greater[i]=sum(n)-sum(y),Lower[i]=sum(y-1);
        // 每处理一个数，就把ai加入到集合中去，相当于在ai这个位置上+1
        add(y,1);
    }

    memset(tree,0,sizeof tree);
    LL res1=0,res2=0;
    // 从右向左扫描
    for(int i=n;i;i--)
    {
        int y=a[i];
        // a[i]右边：[y+1,n]中有多少个数是大于ai的，[1,y-1]中多少个数是小于ai的
        // 左右两边相乘为V和倒V的数量了
        res1+=Greater[i]*1LL*(sum(n)-sum(y));
        res2+=Lower[i]*1LL*sum(y-1);
        // 每处理一个数，就把ai加入到集合中去，相当于在ai这个位置上+1
        add(y,1);
    }

    printf("%lld %lld\n",res1,res2);
    
    return 0;
}