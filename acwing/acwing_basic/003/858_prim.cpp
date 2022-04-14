#include <iostream>
#include <cstring>
using namespace std;

const int N = 510,INF = 0x3f3f3f3f;
// grid����Ϊ�ǳ���ͼ������Ҫ���ٽ�������洢ͼ��dist��ʾʣ��ڵ㵽��С���������ϵ���̾���
int grid[N][N],dist[N];
// ��¼����i�Ƿ�����������
bool flag[N];

int n,m;

int prim()
{
    // ��ʼ����������ͱ������
    memset(dist,0x3f,sizeof dist);
    memset(flag,0,sizeof flag);

    int res=0;

    // ����n�Σ���Ѱ����̾���
    for(int i=0;i<n;++i)
    {
        int t=-1;
        // Ѱ�Ҽ�����ĵ�--�����ϵ���̾���
        for(int j=1;j<=n;++j)
            // t=-1��ʾ��ǰ��û���ҵ��κ�һ����
            if(!flag[j]&&(t==-1||dist[j]<dist[t]))
                t=j;
        
        // i ���ǵ�һ���㣬dist[t]ΪINF��������С�������ľ��벻���ڣ���ͼ�ǲ���ͨ��
        if(i&&dist[t]==INF)return INF;
         
        // ��һ���㵽���ϵľ���Ϊ0�������㵽���ϵ���̾���Ϊdist[t]������t������С������
        if(i)res+=dist[t];
        flag[t]=true;

        // ���µ���С����������С���룬t->jΪ����
        for(int j=1;j<=n;++j)dist[j]=min(dist[j],grid[t][j]);
    }

    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    // �ȳ�ʼ���ڽӾ���
    memset(grid,0x3f,sizeof grid);

    // �Ի���ʼ��Ϊ0
    for(int i=1;i<=n;++i)grid[i][i]=0;

    while(m--)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        // ����Ϊ����ͼ����Ҫ���������ߣ��������ڴ����رߣ�����Ҫ������С�ı�
        grid[x][y]=grid[y][x]=min(grid[x][y],w);
    }

    int t=prim();
    if(t==INF)puts("impossible");
    else printf("%d\n",t);

    return 0;
}