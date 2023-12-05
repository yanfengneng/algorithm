#include <bits/stdc++.h>
using namespace std;

// 方向数组：上右下左
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int bfs(string start)
{
    // 使用字符串来表示棋盘的状态
    // 声明队列和距离数组
    queue<string> q;
    unordered_map<string,int> dist;
    // 将起点加入队列和距离数组
    q.push(start),dist[start]=0;
    // 终点的状态
    string end="12345678x";

    // 开始进行 BFS
    while(q.size())
    {
        auto t=q.front();q.pop();
        // 状态 t 的距离
        int distance=dist[t];
        // 由于 bfs 是加入队列时就将状态的距离进行更新，那么当前状态为终点时，直接返回距离
        if(t==end)return distance;

        // 字符'x'在一维字符串中的坐标以及对应3*3矩阵中的坐标
        int k=t.find('x');
        int x=k/3,y=k%3;

        // 开始进行 4 个方向的状态转移
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            // 坐标越界，则直接跳过
            if(nx<0||ny<0||nx>2||ny>2)continue;
            // (nx,ny)在一维字符串中的坐标为 nx*3+ny
            // 更新状态
            swap(t[k],t[nx*3+ny]);
            // 若扩展到的状态没有被访问过，则更新到该状态的距离，并加入队列
            if(!dist.count(t)){
                q.push(t),dist[t]=distance+1;
            }
            // 恢复状态
            swap(t[k],t[nx*3+ny]);
        }
    }
    // 所有的状态遍历后，还未找到最终答案，返回 -1
    return -1;
}

int main()
{
    string start;
    for(int i=0;i<9;++i){
        char c;cin>>c;
        start+=c;
    }

    printf("%d\n",bfs(start));
    return 0;
}