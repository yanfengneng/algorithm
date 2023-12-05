#include <iostream>
#include <cstring>
using namespace std;

const int V = 510;      //V表示总顶点数
int cost[V][V];         //用邻接矩阵来存放图，cost[u][v]表示边e={u,v}的权值(不存在这条边设为0x3f)
int dist[V];            //顶点s出发的最短距离
bool used[V] = {false}; //表示是否使用顶点

int m,n;

//朴素dijstra的时间复杂度为：O(n^2)
int dijkstra(int s)
{
    memset(dist,0x3f,sizeof(dist));//初始化dist
    dist[s]=0;
    while(true){//while的次数最多执行V-1次，因为最短路不会经过同一个顶点两次
        int v=-1;
        //取出最小值，可优化
        for(int u=1;u<=n;++u){//从尚未使用过的顶点中选择一个距离最小的顶点
            if(!used[u]&&(v==-1||dist[u]<dist[v])){//可松弛
                v=u;
            }
        }
        if(v==-1)break; //表示所有顶点已经选择完成了
        used[v]=true;   //标记该顶点已使用，加入最短路了

        //更新边{v,u}之间的距离，数值的更新也可优化
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
        cost[a][b]=min(cost[a][b],c);//如果发生重边，则保留最短的一条边
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