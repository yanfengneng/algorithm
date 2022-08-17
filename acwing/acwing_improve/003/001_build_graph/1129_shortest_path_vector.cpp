#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
#define x first
#define y second
const int N = 2510, M = 6200*2 + 10;
int n,m,S,T;
int dist[N];            // �������飬��¼Դ�㵽���������̾���
bool v[N];              // ������飬��Ƕ����Ƿ񱻷��ʹ�
vector<PII> graph[M];   // �ڽӱ��洢����ͼ
int cost[N][N];         // �ڽӾ��󣬴洢����ͼ

// �����ڽӱ�
void bulid_adjacent_list()
{
    // ��������ͼ
    for(int i=0;i<m;++i){
        int a,b,w;scanf("%d%d%d",&a,&b,&w);
        // ������ab ba��ȨֵΪw
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
}

// �����ڽӾ���
void build_adjacent_array()
{
    memset(cost,0x3f,sizeof cost);
    // ��������ͼ
    for(int i=0;i<m;++i){
        int a,b,w;scanf("%d%d%d",&a,&b,&w);
        // ������ab ba��ȨֵΪw
        cost[a][b]=cost[b][a]=w;
    }
}

// ���ذ�dijkstra�㷨
int dijkstra(int s,int t)
{
    // �����ڽӾ���
    build_adjacent_array();
    // ��ʼ��Դ�㵽��������ľ���Ͷ�����
    memset(dist,0x3f,sizeof dist),memset(v,0,sizeof v);
    // ��Դ��ľ����ʼ��Ϊ0
    dist[s]=0;

    // ���ڶ����Ǵ�1��ʼ�ģ���1��ʼ����
    // ��������һ���߲����ܾ���һ���������Σ��������ִ��n-1��
    for(int i=1;i<n;++i)
    {
        int x=-1;
        // ��δ��ǵĵ���Ѱ�Ҿ�����С�ĵ�
        for(int j=1;j<=n;++j)
            if(!v[j]&&(x==-1||dist[j]<dist[x]))x=j;

        // ��ʾ���е����̾����Ѿ��������ˣ�ֱ���˳�
        if(x==-1)break;

        // ��ȫ����Сֵ��x�����������ڵ�
        // ����dijkstra�㷨�ǻ���̰�ĵģ������Ѿ�ȷ��Ϊ��С����ĵ㲻�ᱻ����
        // ����ʱy������δ�����ʹ��ĵ㣬Ȼ��ͨ��x���Ƿ��ܽ��и���
        v[x]=true;
        for(int y=1;y<=n;++y)
            dist[y]=min(dist[y],dist[x]+cost[x][y]);
    }
    return dist[t];
} 

// ���Ż���dijksta�㷨
int dijkstra_heap(int s,int t)
{
    // �����ڽӱ�
    bulid_adjacent_list();
    // ��ʼ����Դ�����̾���
    memset(dist,0x3f,sizeof dist);
    // ��Դ��ľ����ʼ��Ϊ0
    dist[s]=0;
    // ��ʼ��С���ѣ�firstΪ��̾��룬secondΪ������
    // ���öѵ��Զ������ܣ���̾�������ڶ�ͷ
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,s});
    // ע����Ż����dijstra�㷨�ǵ�������ǽ��д��ǣ���Ϊֻ��ֻ�жѶ��������ĵ����ȷ����Сֵ�����ֻ���ڳ����е�ʱ��Ե����
    // ��ʼ����s�����е����̾���
    while(heap.size())
    {
        // ȡ���Ѷ�Ԫ�ص�ʱ�临�Ӷ�ΪO(1)��������n��Ԫ�أ�ʱ�临�Ӷ�ΪO(n)
        // i Ϊ�����ţ�d Ϊ��̾���
        auto [d,i]=heap.top();heap.pop();
        // ������ i �����ʹ��ˣ����ý����ɳ���
        if(v[i])continue;
        v[i]=true;
        // ���� i �������ڽӵ㣬�ж��Ƿ�����ɳڡ��������ʱ�临�Ӷ�ΪO(m)
        for(auto [j,w]:graph[i]){
            // ���ɳڣ�������ڽӵ�
            if(dist[j]>dist[i]+w){
                dist[j]=dist[i]+w;
                // �Ѳ���Ԫ���ǲ��ڶ�β��Ȼ������ϸ�������ʱ�临�Ӷ�ΪO(logn)
                heap.push({dist[j],j});
            }
        }
    }
    return dist[t];
}

int spfa(int s,int t)
{
    // �����ڽӱ�
    bulid_adjacent_list();
    // ��ʼ����������ͱ������
    memset(dist,0x3f,sizeof dist),memset(v,0,sizeof v);
    // ��Դ��ľ����ʼ��Ϊ0�������Դ��
    dist[s]=0,v[s]=true;
    // ��Դ�������
    queue<int> q;q.push(s);
    // ÿ�δӶ�����ȡ�����Ǿ����̵ĵ�
    while(q.size()){
        int i=q.front();q.pop();
        // ����i�����ˣ����Ϊfalse
        v[i]=false;
        // ������i�����г��ߣ��� i->j ȨֵΪ w
        // ��ΪԴ�㵽����i����̾����С�ˣ���ô������iΪ���ı�ij�����С
        for(auto [j,w]:graph[i]){
            if(dist[j]>dist[i]+w){
                dist[j]=dist[i]+w;
                // ������j���ڶ����У���������
                // ������j����̾����С�ˣ��ͼ�����С����������Ѿ����������j�ˣ��Ͳ����ظ�����ˡ�
                if(!v[j])q.push(j),v[j]=true;
            }
        }
    }
    return dist[t];
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&S,&T);
    
    cout<<dijkstra_heap(S,T)<<endl;
    return 0;
}