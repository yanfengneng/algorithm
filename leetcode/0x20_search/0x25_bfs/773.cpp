#include <bits/stdc++.h>
using namespace std;

// 方向数组：上右下左
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& g) {
        // 使用字符串来存储棋盘状态
        string start;
        for(int i=0;i<2;i++)for(int j=0;j<3;j++)start+=(g[i][j]+'0');
        // 终点棋盘的状态
        string end="123450";

        // 声明队列和距离数组
        queue<string> q;
        unordered_map<string,int> dist;
        // 将起点加入队列和距离数组
        q.push(start),dist[start]=0;

        // 开始进行 bfs
        while(q.size())
        {
            auto t=q.front();q.pop();
            // 当前状态 t 的距离
            int distance=dist[t];
            // 由于 bfs 是加入队列时就将状态的距离进行更新，那么当前状态为终点时，直接返回距离
            if(t==end)return distance;
            // 字符'0'在一维字符串中的坐标，以及转换为 2*3 的矩阵的坐标
            int k=t.find('0');
            int x=k/3,y=k%3;

            // 进行 4 个方向的枚举
            for(int i=0;i<4;++i)
            {
                int nx=x+dx[i],ny=y+dy[i];
                // 判断是否越界，越界直接跳过
                if(nx<0||ny<0||nx>1||ny>2)continue;
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

        // 最终未到达终点状态，返回 -1
        return -1;
    }
};

int main()
{
    vector<vector<int>> g={{1,2,3},{5,4,0}};
    cout<<Solution().slidingPuzzle(g)<<endl;
    return 0;
}