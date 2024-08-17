#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char g[N][N];
int dist[N][N];
using PII = pair<int ,int>;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m;

void bfs()
{
    // ���ڶ�Դ BFS ����ӿ�ʼ������Сֵ�ˣ�Ҳ����һ�����֮�����ľ����ǲ��ᱻ���µģ�Ҳ���Ǿ���ֻ�ᱻ����һ�Σ����Բ���Ҫ��ʼ��Ϊ0x3f��ֻ���ʼ��һ������ֵ-1����
    memset(dist,-1,sizeof dist);
    queue<PII> q;
    // �����е�����Ԫ�ض��ǵ��������ģ��������бߵ�Ȩ�ض�һ������1����˺����ľ�����һ�����ڶ�ͷ��ľ���ģ�����һ��һ��Ԫ�ر���ͷ�����ˣ���һ�����ᱻ������κ�һ��Ԫ�ؽ��и����ˣ�Ҳ����ֻ�ᱻ����һ��
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(g[i][j]=='1')dist[i][j]=0,q.push({i,j});
    
    // ���²��ֺ͵�ԴBFSһ����
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            // Խ����߾����Ѿ�����������ˣ����÷����������
            if(nx<0||ny<0||nx>=n||ny>=m||dist[nx][ny]!=-1)continue;
            // ���¾��룬���������
            dist[nx][ny]=dist[x][y]+1;
            q.push({nx,ny});
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",g[i]);

    bfs();
    // ������о���
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)printf("%d ",dist[i][j]);
        puts("");
    }
    return 0;
}