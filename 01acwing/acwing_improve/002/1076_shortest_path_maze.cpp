#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
const int N = 1010;
using PII = pair<int,int>;
int g[N][N];
// ����Ԫ��Ϊһ��pair����pre����ǵ�ǰ����һ���������
PII pre[N][N];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n;

void bfs(int sx,int sy)
{
    queue<PII> q;
    q.push({sx,sy});
    // ��Ӿ�Ҫ����
    memset(pre,-1,sizeof pre);
    // ����ֻҪŪһ������-1��������
    pre[sx][sy]={0,0};
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            // Խ���������ǽ�˻�����ǰ���Ѿ������ʹ��ˣ�����Ҫ���ʸõ���
            if(nx<0||ny<0||nx>=n||ny>=n||g[nx][ny]||pre[nx][ny].x!=-1)continue;
            // ��Ӳ����д���
            q.push({nx,ny});
            // ��ǰ�����һ����Ϊ(x,y)
            pre[nx][ny]={x,y};
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&g[i][j]);
    
    // ���յ㷴�Ƶ�����·��
    bfs(n-1,n-1);
   
    PII end={0,0};
    while(1)
    {
        printf("%d %d\n",end.x,end.y);
        if(end.x==n-1&&end.y==n-1)break;
        end=pre[end.x][end.y];
    }

    return 0;
}