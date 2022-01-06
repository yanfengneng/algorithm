#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

using PII = pair<int,int>;
const int N = 1e6+10;

// �ڽӱ�hΪ��ͷ���飬wΪȨֵ��eΪ��Ŷ���ı�ţ�neΪnext���飬idxΪ��ǰ���õĽڵ���
int h[N],w[N],e[N],ne[N],idx=0;
int dist[N];
bool flag[N];
int n,m;

// �����ab�ұߵ�ȨֵΪc 
void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

// ��ʱ�临�Ӷ�ΪO(mlogn)
int dijkstra(int s)
{
    // ��ʼ������
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;

    // ��ʼ��С���ѣ�firstΪ��̾��룬secondΪ������
    // ���öѵ��Զ������ܣ���̾�������ڶ�ͷ
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,s});

    // ��ʼ����s�����е����̾���
    while(!heap.empty())
    {
        // ȡ���Ѷ�Ԫ�ص�ʱ�临�Ӷ�ΪO(1)��������n��Ԫ�أ�ʱ�临�Ӷ�ΪO(n)
        auto t=heap.top();
        heap.pop();

        // v Ϊ�����ţ� distance Ϊ��̾���
        int v=t.second,distance=t.first;

        // �� v �����ʹ��ˣ����ý����ɳ���
        if(flag[v])continue;
        flag[v]=true;

        // ��������v�������ڽӵ㣬�������ʱ�临�Ӷ�ΪO(m)
        for(int i=h[v];i!=-1;i=ne[i])
        {
            // �ڽڵ�j
            int j=e[i];
            // �����ڽڵ����̾���
            if(dist[j]>distance+w[i])
            {   
                dist[j]=distance+w[i];
                // �Ѳ���Ԫ���ǲ��ڶ�β��Ȼ������ϸ�������ʱ�临�Ӷ�ΪO(logn)
                heap.push({dist[j],j});
            }
        }
    }

    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    int t;
    scanf("%d",t);
    while(t--)
    {
        scanf("%d%d",&n,&m);

        // ��ʼ���ڽӱ�
        memset(h,-1,sizeof h);
        memset(w,0,sizeof w),memset(e,0,sizeof e),memset(ne,0,sizeof ne);
        idx=0;
        while(m--)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
            add(y,x,z);
        }

        printf("%d\n",dijkstra(0));
    }
    
    return 0;
}