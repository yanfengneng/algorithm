#include<iostream>
#include<vector>

using namespace std;

int g[15][15];
bool visited[15][15];
int n;
int res=0;

// 方向数组
int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};

void dfs(int i,int j)
{
    if(i==0&&j==n-1)
    {
        res++;
        return;
    }
    for(int k=0;k<8;++k)
    {
        int x=i+dx[k],y=j+dy[k];
        if(x>=0&&x<n&&y>=0&&y<n&&!visited[i][j]&&!g[i][j])
        {
            visited[i][j]=1;
            dfs(x,y);
            visited[i][j]=0;
        }
    }
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&g[i][j]);
    dfs(0,0);
    printf("%d",res);
	return 0;
}
/*
3 
0 0 0
0 1 1
1 0 0
*/