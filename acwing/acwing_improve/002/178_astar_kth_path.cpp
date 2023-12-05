#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
using PIII = pair<int,PII>;
// ���������
const int INF = 0x3f3f3f3f;

const int N = 1010;
// ��������ͼ�ڽӱ�����ͼ�ڽӱ�
vector<PII> g[N],rg[N];
int n,m,S,T,K;
// ʹ�� dijkstra �㷨�����㵽�յ����̾�������Ϊ��������
int dist[N];
// ���Ż����dijkstra�㷨����ʹ�ô������ڵ���ظ�����
bool v[N];

void dijkstra()
{
    // ����С���ѣ��ڵ�ֵΪ <���յ�ľ��롢�ڵ���>
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dist,0x3f,sizeof dist),memset(v,false,sizeof v);
    // �����յ㣬��ʼ���յ����
    q.push({0,T});dist[T]=0;
    // ע����Ż���� dijstra �㷨�ǵ�������ǽ��д��ǣ���Ϊֻ��ֻ�жѶ��������ĵ����ȷ����Сֵ�����ֻ���ڳ����е�ʱ��Ե����
    while(q.size())
    {
        auto [distance,i]=q.top();q.pop();
        // ������ i �ѱ����ʣ�������
        if(v[i])continue;
        // �Զ��� i �����Ǵ���
        v[i]=true;
        // �������� i �������ڽӵ㣬���ܸ��µĵ���и���
        for(auto [j,w]:rg[i])
        {
            // ������ j �ľ�����ɳڣ�����и���
            if(dist[j]>dist[i]+w)
            {
                dist[j]=dist[i]+w;
                q.push({dist[j],j});
            }
        }
    }
}

int astar()
{
    // �յ㵽�ﲻ����㣬Ҳ���޽�ֱ�ӷ��� -1
    if(dist[S]==INF)return -1;

    // <����ֵ���룬<��ʵֵ���룬��չ���Ķ����� j>>
    // ����ֵ���� = ��� S ������ i �ľ��� + ���� i ������ j �ľ��� + ���� j ���յ� T �ľ���
    // ��ʵ���� = ��� S ������ i �ľ��� + ���� i ������ j �ľ���
    priority_queue<PIII,vector<PIII>,greater<PIII>> heap;
    // ��ʼ A* �㷨����㿪ʼ����
    heap.push({dist[S],{0,S}});
    // ������¼�յ㱻�����Ĵ�������һ�α������յ�ʱ���ǵ�һС�ľ���...��k�α������յ�ʱ���ǵ�kС�ľ���
    int cnt=0;
    while(heap.size())
    {
        // distance ��ʾ����� S ������ i ����ʵ����
        auto t=heap.top();heap.pop();
        int i=t.y.y,distance=t.y.x;
        // �������յ��ˣ����м���
        if(i==T)cnt++;
        // Ѱ�ҵ� k С�����·��ֵ�ˣ���ֱ�ӷ��ظ����·��ֵ
        if(cnt==K)return distance;
        // ������չ���еıߣ�
        // ����ֵ���� = ��� S ������ i �ľ��� + ���� i ������ j �ľ��� + ���� j ���յ� T �ľ�������Ϊ��׼��
        // ��ʵ���� = ��� S ������ i �ľ��� + ���� i ������ j �ľ���
        // ��չ���Ķ����� j
        // dist > d���� > d[i]+f[i] ��������õ��Ŀ϶�����Сֵ
        for(auto [j,w]:g[i]){
            heap.push({distance+w+dist[j],{distance+w,j}});
        }
    }
    return -1;
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