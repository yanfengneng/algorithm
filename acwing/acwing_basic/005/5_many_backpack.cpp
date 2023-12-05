#include <iostream>
#include <algorithm>
using namespace std;

const int N = 12010,V = 2010;

int n,m;
int v[N],w[N];
int f[V];

int main()
{
    scanf("%d%d",&n,&m);

    // 用cnt存储新的物品体积和价值的编号
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        int a,b,s;
        scanf("%d%d%d",&a,&b,&s);
        int k=1;
        // 只要k<=s，都可以把s分组
        // 整数s被分解成k个二进制数，那么则k个二进制数一定可以表示小于等于s的所有整数
        // s=2^0+2^1+...+2^(k-1)+c ==>> 这k+1个数字选与不选，共2^(k+1)种选择，刚好能表示小于等于s的所有整数
        // 总结一句话就是说将s分解成k位二进制数了，在这k位上：每位上0表示不选，1表示选，所以能表示所有小于等于s的所有数字
        while(k<=s)
        {
            cnt++;// 先把新的物品编号+1

            // k个物品一组，每组里面物品的体积和价值都扩大k倍
            v[cnt]=a*k;
            w[cnt]=b*k;

            // 然后将总组数减掉k，再将k扩大两倍，下一组的大小为2*k
            s-=k;
            k*=2;
        }
        // 最后s还大于0，我们还剩余一组，需要补上
        if(s>0)   
        {
            cnt++;
            v[cnt]=a*s,w[cnt]=b*s;
        }
    }

    // n 为新的物品个数
    n=cnt;
    for(int i=1;i<=n;++i)
        for(int j=m;j>=v[i];--j)
            // 由于j是由大到小枚举的，所以这里的f[j-v]没有被计算过，是第i-1层的f[j-v]
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    
    printf("%d\n",f[m]);
    return 0;
}