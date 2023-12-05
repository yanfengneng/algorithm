#include <iostream>
#include <cstring>
using namespace std;

int n,m,k;

const int N = 510,M = 1e4+10;
int dist[N],backup[N];

// ����a������b��ȨֵΪw
struct Edge
{
    int a,b,w;
}edges[M];

int bellman_ford(int s)
{
    // ��ʼ������
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;

    // ����k�α�����ʾ��1�ŵ㵽n�ŵ㲻����k���ߵ���̾���
    for(int i=0;i<k;++i)
    {
        // ��dist���ݵ�backup��
        memcpy(backup,dist,sizeof dist);

        // �������еı�
        for(int j=0;j<m;++j)
        {
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            // ����b����̾��룬Ϊ�˷�ֹ������������Ҫʹ����һ�ε�dist
            // ��Ϊ����д����ԣ����������ǹ̶��ģ�����ֻ��ֻ����һ�ε�dist
            dist[b]=min(dist[b],backup[a]+w);
        }
    }

    // �����Ҳ���ܸ���ΪСһ����������Ҫ�ж�һ��
    if(dist[n]>0x3f3f3f/2)return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<m;++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edges[i]={x,y,z};
    }

    if(bellman_ford(1)==-1)puts("impossible");
    else printf("%d\n",dist[n]);

    return 0;
}