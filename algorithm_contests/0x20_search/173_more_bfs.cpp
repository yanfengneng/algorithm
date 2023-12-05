#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
const int N = 1010;

char s[N][N];
int d[N][N],n,m;

// ��������
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void bfs()
{
    // ��Դbfs�ĳ�ʼ��
    queue<PII> q;
    memset(d,-1,sizeof d);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(s[i][j]=='1'){
                d[i][j]=0;
                q.push({i,j});
            }
    // ��ʼbfs
    while(!q.empty())
    {
        // ����t��4���������̾���
        auto t=q.front();q.pop();
        for(int i=0;i<4;++i)
        {
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=1&&x<=n&&y>=1&&y<=m&&d[x][y]==-1)
            {
                // ������̾���
                d[x][y]=d[t.first][t.second]+1;
                q.push({x,y});
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);

    bfs();

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            printf("%d ",d[i][j]);
        puts("");
    }    
    return 0;
}