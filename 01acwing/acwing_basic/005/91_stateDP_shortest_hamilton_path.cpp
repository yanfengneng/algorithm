#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 1 << 20;
// 状态f[state][j]=c：二进制数state表示当前使用过那些点，j表示当前停在那个点上；数值c表示最短路径值
int f[M][N];
// 需要输入的数据
int n,weight[N][N];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&weight[i][j]);
    
    memset(f,0x3f,sizeof f);
    // 起点为顶点0，起点0对应的二进制数就是第0位被使用了，对应十进制数为1
    f[1][0]=0;

    // 开始进行状态转移
    // 运算符优先级：(+-) > (移位<< >>) > (比较大小)
    for(int s=1;s<1<<n;++s)// 枚举所有使用过的点，最后n个点都被使用的二进制数为1<<n-1
        for(int j=0;j<n;++j)// 枚举当前停在那个点上
            if(s>>j&1)// s中的第j个点存在，则枚举中间点k，用来更新到第j个点的最短距离
                for(int k=0;k<n;++k)
                   if(s-(1<<j)>>k&1) // s中除去j点，并且经过k点的集合，而且现在就位于第k个点上。用k点到j点来更新最短路径
                        f[s][j]=min(f[s][j],f[s-(1<<j)][k]+weight[k][j]);
    
    // 最终答案就是使用了n个点，且现在位于第n-1个点上的最短路径
    cout<<f[(1<<n)-1][n-1]<<endl;
    return 0;
}