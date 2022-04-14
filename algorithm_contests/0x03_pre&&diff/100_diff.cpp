#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using LL = long long;
int a[N],n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    // 逆序求差分数组
    for(int i=n;i>1;i--)a[i]-=a[i-1];
    // 统计差分数组[2,n]中的正数和pos和负数和的绝对性neg
    LL pos=0,neg=0;
    for(int i=2;i<=n;++i)
        if(a[i]>0)pos+=a[i];
        else neg-=a[i];
    // 最少操作数为min(pos,neg)+abs(pos-neg)=max(pos,neg)，能产生abs(pos-neg)+1种不同的b1值
    printf("%lld\n",max(pos,neg));
    printf("%lld\n",abs(pos-neg)+1);
    return 0;
}