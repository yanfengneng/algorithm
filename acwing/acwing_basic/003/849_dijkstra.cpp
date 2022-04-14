#include <iostream>
#include <cstring>
using namespace std;

int n,m;
const int N = 510;
// ���ڱ���Ϊ����ͼ���������ڽӾ�����Ч����
// cost��������ڽӾ���dist���������̾���
int cost[N][N],dist[N];
// visited������ǵ��Ƿ�ʹ��
bool visited[N];

// �����Դ��s�������������е����̾���
int dijkstra(int s)
{
    // ��ʼ������Ͷ�����
    memset(dist,0x3f,sizeof dist);
    memset(visited,0,sizeof visited);
    dist[s]=0;

    // ���ڶ����Ǵ�1��ʼ�ģ���1��ʼ����
    // ��������һ���߲����ܾ���һ���������Σ��������ִ��n-1��
    for(int i=1;i<n;++i)
    {
        int x=-1;
        // ��δ��ǵĵ���Ѱ�Ҿ�����С�ĵ�
        for(int j=1;j<=n;++j)
            if(!visited[j]&&(x==-1||dist[j]<dist[x]))x=j;

        // ��ʾ���е����̾����Ѿ��������ˣ�ֱ���˳�
        if(x==-1)break;

        // ��ȫ����Сֵ��x�����������ڵ�
        // ����dijkstra�㷨�ǻ���̰�ĵģ������Ѿ�ȷ��Ϊ��С����ĵ㲻�ᱻ����
        // ����ʱy������δ�����ʹ��ĵ㣬Ȼ��ͨ��x���Ƿ��ܽ��и���
        visited[x]=true;
        for(int y=1;y<=n;++y)
            dist[y]=min(dist[y],dist[x]+cost[x][y]);
    }

    // ��������̾���ͷ���-1�����򷵻���̾���
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d",&n,&m);
    // ��ʼ���ڽӾ���
    memset(cost,0x3f,sizeof cost);
    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        // ���ڴ����Ի����رߣ����ǽ��豣����̵�Ȩֵ������
        cost[x][y]=min(cost[x][y],z);
    }

    printf("%d\n",dijkstra(1));
    return 0;
}