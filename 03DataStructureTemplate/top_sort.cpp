#include <bits/stdc++.h>
using namespace std;

vector<int> top_sort(int n,vector<vector<int>>& a)
{
    vector<vector<int>> g(n);   // 邻接表
    vector<int> indegrees(n);   // 顶点入度表
    for(int i=0;i<n;++i){
        // 边 j->i
        for(int j:a[i])g[j].push_back(i);
        // 顶点 i 的度为所有指向顶点 i 的顶点数
        indegrees[i]=a[i].size();
    }
    // 入度为 0 的顶点入队列
    queue<int> q;
    for(int i=0;i<n;++i)
        if(!indegrees[i])q.push(i);
    // 开始进行 bfs，获得拓扑序列
    vector<int> res;
    while(q.size()){
        auto i=q.front();q.pop();
        // 入度为 0 的顶点加入拓扑序列
        res.push_back(i);
        // 删除边 i->j 
        for(int j:g[i])
            if(--indegrees[j]==0)q.push(j);
    }
    // 若为有向无环图，则拓扑系列有 n 个顶点；若存在环，则拓扑序列中的顶点个数必然小于 n，因为环中不存在入度为 0 的顶点，无法加入，所有存在环的话，顶点个数必然小于 n
    return res.size()==n?res:vector<int>();
}

int main()
{
    vector<vector<int>> a={{},{6},{5},{6},{3,6},{},{},{}};
    auto res=top_sort(8,a);
    for(auto x:res)cout<<x<<" ";
    cout<<endl;
    return 0;
}