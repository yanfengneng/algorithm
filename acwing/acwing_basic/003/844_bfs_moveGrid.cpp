#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

using PII=pair<int,int>;
const int N = 110;

int n,m;
int grid[N][N],dist[N][N];

// ���У�pre������¼·��
PII q[N*N],pre[N][N];

// 4����������
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int bfs()
{
    // ��ʼ�����У�����(0,0)���������
    // ������Ѷ�βtt��ʼ��Ϊ0����Ϊ����{0,0}��tt��-1���0��
    int hh=0,tt=0;
    q[0]={0,0};
    
    // ��ʼ������
    memset(dist,-1,sizeof dist);
    dist[0][0]=0;

    // ���в�Ϊ��
    while(hh<=tt)
    {
        // ��ͷ������
        auto t=q[hh++];

        // ��t��Χ���ĸ���ľ������
        for(int i=0;i<4;++i)
        {
            int x=t.first+dx[i],y=t.second+dy[i];
            // (x,y)û��Խ���ҿ��Կ�����ͨ������dist[x][y]û�б��߹�
            if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==0&&dist[x][y]==-1)
            {   
                // ���¾��룬���������
                dist[x][y]=dist[t.first][t.second]+1;
                // (x,y)��ǰһ����Ϊt����t->(x,y)
                pre[x][y]=t;
                q[++tt]={x,y};
            }
        }
    }

    int x=n-1,y=m-1;
    // ����BFS������ȨֵΪ1��ͼ�����Դ���㵽�յ�ľ�����ʵΪ���·���ȼ���BFS�����Ĳ���
    // prev�����Ǹ��ݲ�������¼ǰһ���������ģ���˴��յ㵽���Ĳ����������ĵ㼴Ϊ���·���յ�Ҳֻ�ܴ����·��ȥ
    while(x||y)
    {
        cout<<x<<" "<<y<<endl;
        auto t=pre[x][y];
        x=t.first,y=t.second;
    }
    return dist[n-1][m-1];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&grid[i][j]);
    printf("%d\n",bfs());
    return 0;
}