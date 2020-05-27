#include <bits/stdc++.h>
using namespace std;

int n,m;
int dist[100010];
map<int,vector<pair<int,int>>> adjacent;

//dijstra堆优化，时间复杂度O((V+E)*logV)，数值插入和最小值取出使用小根堆，这样来降低复杂度
//优化版的dijkstra是针对数值的插入（更新）和取出最小值进行优化的
//取出最小值的时间复杂度为O(logV)，因为堆中有V个顶点
//堆的插入和更新的总时间复杂度为O(E)，因为更新和插入每条边都会遍历到，然而添加到堆里面只有V个元素
int dijstra2(int s){
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    //pair的first表示最短路径，second表示源点s
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //小根堆
    q.push(make_pair(0, s));
    while(!q.empty()){
        //因为堆中有V个元素，所以取出最小的时间复杂度为O(logV)
        pair<int,int> p=q.top();q.pop();
        int v=p.second;
        if(dist[v]<p.first)continue;//取出的最小值不是最短距离，丢弃该值
        for (const auto &edge : adjacent[v]){//遍历顶点v的邻接点，进而更新顶点v的邻节点的最短距离
            //更新顶点v的邻接点的最短距离，并添加到q中，first为顶点v的邻接点，second为边v first的权值
            if (dist[edge.first] > dist[v] + edge.second){
                dist[edge.first] = dist[v] + edge.second;
                q.push(make_pair(dist[edge.first], edge.first));
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    while (m--){ //构建邻接表
        int a, b, c;
        cin>>a>>b>>c;
        adjacent[a].push_back(make_pair(b, c));
    }
    cout << dijstra2(1) << endl;
    return 0;
}