#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int g[N][N];
// ������飺��ʾ�õ��Ƿ񱻷��ʹ�
bool v[N][N];
using PII = pair<int,int>;
// �������飺��������
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};

int n,m;

// ���п��ѹ��
int bfs(int i,int j)
{
    queue<PII> q;
    q.push({i,j});
    // ��ʷ����ʵ�������ǽ����о�Ҫ����
    v[i][j]=1;
    int area=0;
    while(q.size())
    {
        // ������ʱͳ�Ʒ������
        auto [x,y]=q.front();q.pop();
        area++;
        for(int k=0;k<4;++k)
        {
            int nx=x+dx[k],ny=y+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=m||v[nx][ny])continue;
            // ��(x,y)��k������Ϊǽ���Ͳ��ܽ���ͳ����
            if(g[x][y]>>k&1)continue;
            // �����У������ϱ��
            q.push({nx,ny});
            v[nx][ny]=1;
        }
    }
    return area;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&g[i][j]);
    
    int cnt=0,area=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(!v[i][j])
            {
                cnt++;
                area=max(area,bfs(i,j));
            }
    printf("%d\n%d\n",cnt,area);
    return 0;
}