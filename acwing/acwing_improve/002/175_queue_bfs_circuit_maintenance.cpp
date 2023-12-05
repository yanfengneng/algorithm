#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using PII = pair<int,int>;

const int N = 510;
// ��̾�������
int dist[N][N];
// ���ڱ�����ڱ�ȨΪ0�ıߣ�ʹ��˫�˶���ʱ������ظ����ʵ㣬�����Ҫʹ��һ���������
bool vis[N][N];
// ��������
int n,m;
char g[N][N];

// '/' ��Ҫת�壬��[���ϡ����ϡ����¡�����]��˳������ĸ������ö��
char cs[]="\\/\\/";
// ��������
int dx[]={-1,-1,1,1},dy[]={-1,1,1,-1};
// ��Ҫ�ȹ��ĸ��ӷ���
int ix[]={-1,-1,0,0},iy[]={-1,0,0,-1};

int bfs()
{
    // ��ʼ����������ͱ�ǵ�����
    memset(dist,0x3f,sizeof dist),memset(vis,false,sizeof vis);
    // ��ʼ�����ľ��룬�Լ���������˫�˶���
    dist[0][0]=0;
    deque<PII> q;
    q.push_back({0,0});
    // ��ʼ���� bfs
    while(q.size())
    {
        // ��ö�ͷ���꣬������ͷ����
        auto [x,y]=q.front();q.pop_front();
        // ����Ż���dijkstar�㷨һ���������ڳ��ӵ�ʱ���֪��ÿ�����������̾��룬��һ���bfs�Ž����е�ʱ���֪����̾����ˡ�
        if(x==n&&y==m)return dist[x][y];
        if(vis[x][y])continue;
        // ����ʹ�õ��ǳ�����ʱ���������д��ǣ���Ϊһ������ܱ����ʶ�Σ���˳����д�������ֹ�㱻���ʶ�Ρ�
        vis[x][y]=true;
        // �����ĸ������ö��
        for(int i=0;i<4;++i)
        {
            // ���ӱ߽��ϵ������
            int nx=x+dx[i],ny=y+dy[i];
            // ��չ��Խ���ˣ��������÷������չ
            if(nx<0||ny<0||nx>n||ny>m)continue;
            // �ȵ����ӵ�����
            int gx=x+ix[i],gy=y+iy[i];
            // ����Ҫ��ת����ȨΪ0����Ҫ��ת����ȨΪ1��
            int w=g[gx][gy]==cs[i]?0:1;
            // �ӵ�(x,y)��(nx,ny)�ľ���
            int d=dist[x][y]+w;
            // ���µ����(nx,ny)����̾���
            if(d<dist[nx][ny])
            {
                dist[nx][ny]=d;
                // ��չ�����ĵ��ȨΪ1������ӵ���β����չ�����ĵ��ȨΪ0����ӵ���ͷ��
                if(w)q.push_back({nx,ny});
                else q.push_front({nx,ny});
            }
        }
    }
    return -1;
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)scanf("%s",g[i]);

        // �������Ϊ(0,0)��ż���㣬б���ߵĻ�����������ͬʱ�仯1����λ���������Ҳֻ���ߵ�ż���㡣���յ�Ϊ������Ļ���ֱ����������ܼ��ɡ��������bfs����̾��롣
        // ˫�˶�����Ҫ���ڽ��ͼ�б�Ȩֵֻ�� 0 �� 1 �����·����
        if(n+m&1)puts("NO SOLUTION");
        else printf("%d\n",bfs());
    }

    return 0;
}