#include <iostream>
#include <cstring>
using namespace std;

// 所有长度的和最大为2e8
const int N = 210,INF = 1e9;
// 邻接矩阵
int d[N][N];
int n,m,Q;

// 三维dp
void floyd()
{
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&Q);

    // 重边初始化为0，其他边初始化为最大值
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;

    while(m--)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        // 由于会存在重边，所以我们只需要保留最短的边
        d[x][y]=min(d[x][y],w);
    }

    floyd();

    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        // 因为会存在负环，所以d[x][y]会变小一点点，但是也是不存在最短路
        if(d[x][y]>INF/2)puts("impossible");
        else printf("%d\n",d[x][y]);
    }

    return 0;
}