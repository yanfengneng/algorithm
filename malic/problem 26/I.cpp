#include <iostream>
using namespace std;

char str[110][110];
bool visited[110][110];

// 8个方向数组
int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
int n,m;

void dfs(int i,int j)
{
    visited[i][j]=1;
    for(int k=0;k<8;++k)
    {
        int x=i+dx[k],y=j+dy[k];
        if(x>=0&&x<n&&y>=0&&y<m&&!visited[x][y]&&str[x][y]=='W')
            dfs(x,y);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",str[i]);

    int res=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            if(str[i][j]=='W'&&!visited[i][j])
            {
                dfs(i,j);
                res++;
            }
        }

    printf("%d\n",res);
    return 0;
}