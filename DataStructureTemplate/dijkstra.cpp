#include <iostream>
#include <cstring>
using namespace std;

const int V = 510;      //V��ʾ�ܶ�����
int cost[V][V];         //���ڽӾ��������ͼ��cost[u][v]��ʾ��e={u,v}��Ȩֵ(��������������Ϊ0x3f)
int dist[V];            //����s��������̾���
bool used[V] = {false}; //��ʾ�Ƿ�ʹ�ö���

int m,n;

//����dijstra��ʱ�临�Ӷ�Ϊ��O(n^2)
int dijkstra(int s)
{
    memset(dist,0x3f,sizeof(dist));//��ʼ��dist
    dist[s]=0;
    while(true){//while�Ĵ������ִ��V-1�Σ���Ϊ���·���ᾭ��ͬһ����������
        int v=-1;
        //ȡ����Сֵ�����Ż�
        for(int u=1;u<=n;++u){//����δʹ�ù��Ķ�����ѡ��һ��������С�Ķ���
            if(!used[u]&&(v==-1||dist[u]<dist[v])){//���ɳ�
                v=u;
            }
        }
        if(v==-1)break; //��ʾ���ж����Ѿ�ѡ�������
        used[v]=true;   //��Ǹö�����ʹ�ã��������·��

        //���±�{v,u}֮��ľ��룬��ֵ�ĸ���Ҳ���Ż�
        for(int u=1;u<=n;++u){
            dist[u]=min(dist[u],dist[v]+cost[v][u]);
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(cost,0x3f,sizeof(cost));
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        cost[a][b]=min(cost[a][b],c);//��������رߣ�������̵�һ����
    }
    cout<<dijkstra(1)<<endl;
    return 0;
}
/*
3 3
1 2 2
2 3 1
1 3 4
*/