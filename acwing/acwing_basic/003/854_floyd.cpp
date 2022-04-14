#include <iostream>
#include <cstring>
using namespace std;

// ���г��ȵĺ����Ϊ2e8
const int N = 210,INF = 1e9;
// �ڽӾ���
int d[N][N];
int n,m,Q;

// ��άdp
void floyd()
{
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&Q);

    // �ر߳�ʼ��Ϊ0�������߳�ʼ��Ϊ���ֵ
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;

    while(m--)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        // ���ڻ�����رߣ���������ֻ��Ҫ������̵ı�
        d[x][y]=min(d[x][y],w);
    }

    floyd();

    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        // ��Ϊ����ڸ���������d[x][y]���Сһ��㣬����Ҳ�ǲ��������·
        if(d[x][y]>INF/2)puts("impossible");
        else printf("%d\n",d[x][y]);
    }

    return 0;
}