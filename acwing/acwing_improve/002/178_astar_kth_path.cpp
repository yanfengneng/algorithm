#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
using PIII = pair<int,PII>;

const int N = 1010;
// ��������ͼ�ڽӱ�����ͼ�ڽӱ�
vector<int> g[N],rg[N];
int n,m,S,T,K;
// ʹ�� dijkstra �㷨�����㵽�յ����̾�������Ϊ��������
int dist[N][N];
// ���Ż����dijkstra�㷨����ʹ�ô������ڵ���ظ�����
bool v[N];

void dijkstra()
{
    // ����С���ѣ��ڵ�ֵΪ<���յ�ľ��롢�ڵ���>
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dist,0x3f,sizeof dist),memset(v,false,sizeof v);
    // �����յ㣬��ʼ���յ����
    q.push({0,T}),dist[T]=0;
    // ע����Ż����dijstra�㷨�ǵ�������ǽ��д��ǣ���Ϊֻ��ֻ�жѶ��������ĵ����ȷ����Сֵ�����ֻ���ڳ����е�ʱ��Ե����
    while(q.size())
    {

    }
}

int astar()
{

}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b,l;scanf("%d%d%d",&a,&b,&l);
        // ��������ͼ�ڽӱ�����ͼ�ڽӱ�
        g[a].push_back({b,l}),rg[b].push_back({a,l});
    }
    scanf("%d%d%d",&S,&T,&K);
    // ������յ���ͬʱ����dist[S��S]=0���������Ҫ��ȥ����Ϊ��ĿҪ�����·������Ҫ����һ���ߣ������Ҫ�ų�dist[S��S]=0���������ʹ��kС��ɵ�k+1С
    if(S==T)K++;
    // ʹ�� dijkstra �㷨������ÿ���㵽�յ����̾�������Ϊ��������
    dijkstra();

    printf("%d\n",astar());
    return 0;
}