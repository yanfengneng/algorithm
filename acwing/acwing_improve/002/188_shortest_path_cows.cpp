#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
const int N = 155;
char g[N][N];
int dist[N][N];// ��ʾ��㵽(i,j)�ľ���
int dx[]={-1,-2,-2,-1,1,2,2,1},dy[]={-2,-1,1,2,2,1,-1,-2};// ��ʾ��������
int n,m;

int bfs()
{
    int sx,sy;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(g[i][j]=='K')
            {
                sx=i,sy=j;
                break;
            }
    // ��ʼ����bfs
    // ��ʼ����������Ϊ-1
    memset(dist,-1,sizeof dist);
    queue<PII> q;
    // ��ʼ�����
    q.push({sx,sy});
    dist[sx][sy]=0;
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<8;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            // Խ����������ϰ����������ѷ��ʹ��ĵ�
            if(nx<0||ny<0||nx>=n||ny>=m||g[nx][ny]=='*'||dist[nx][ny]!=-1)continue;
            // �ҵ��յ���
            if(g[nx][ny]=='H')return dist[x][y]+1;
            // �������
            dist[nx][ny]=dist[x][y]+1;
            q.push({nx,ny});
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;++i)scanf("%s",g[i]);
    printf("%d\n",bfs());
    return 0;
}