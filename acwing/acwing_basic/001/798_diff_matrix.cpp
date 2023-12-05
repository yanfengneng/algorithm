#include <iostream>

using namespace std;

const int N=1010;
int a[N][N],b[N][N];
int n,m,q;

void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y1]+=c;
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);

    // 差分数组的初始化
    // 这个差分数组的初始化确实难以理解，但是通过调试的话发现 b 确实被初始化差分数组了
    // 因为在每个小方格在插入 a[i][j] 时，它周围的4个值也会变化，因此在完成a的所有元素插入后，就会形成差分数据，这其中的证明关系就不用管了，记住这个模板就行
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            insert(i,j,i,j,a[i][j]);
    
   
    while(q--)
    {
        int x1,y1,x2,y2,c;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        // 给区间正方形加上 c
        insert(x1,y1,x2,y2,c);
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            // 还原数组 a，求前缀和
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}