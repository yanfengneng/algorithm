#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n,m;
char g[N][N];
// 四个方向：0向上；1向右；2向下；3向左
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int dfs(int x,int y,int d)
{
    // 到达边界，表示走出矩阵了，返回距离0
    if(x<0||y<0||x>=n||y>=m)return 0;

    // 镜子为斜右上时，0->1；3->2；2->3；1->0；刚好满足成对变换，d^1完成转换
    if(g[x][y]=='/')d^=1;
    // 镜子为斜左上时，0->3；1->2；2->1；3->0；这样d异或3刚好完成变换
    else d^=3;

    return dfs(x+dx[d],y+dy[d],d)+1;
}

 int main()
 {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",&g[i]);

    int res=0;
    // 枚举所有的行的起点
    for(int i=0;i<n;++i)
    {
        // 从左往右走，每行的第一个位置(i,0)为起点，向右走
        res=max(res,dfs(i,0,1));
        // 从右往左走，每行的最后一个位置(i,m-1)为起点，向左走
        res=max(res,dfs(i,m-1,3));
    }

    // 枚举所有列的起点
    for(int i=0;i<m;++i)
    {
        // 从上往下走，每列的第一个位置(0,i)为起点，向下走
        res=max(res,dfs(0,i,2));
        // 从下往上走，每列的最后一个位置(n-1,i)为起点，向上走
        res=max(res,dfs(n-1,i,0));
    }
    
    printf("%d\n",res);
    return 0;
 }