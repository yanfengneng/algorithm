#include <iostream>

using namespace std;

const int N=1010;

int a[N][N],s[N][N];

int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
    
    // 二维前缀和的初始化
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    
    while(q--)
    {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        // 计算区间的面积，其实这里我们把x、y当作了一个格子，而原题中是一个点，所以结合画图理解一下
        // 还有下标都是从[1,1]开始的
        printf("%d\n",s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]);
    }

    return 0;
}