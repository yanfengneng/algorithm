#include <bits/stdc++.h>
using namespace std;

const int N = 510;
// 标记数组
int v[N][N];
// 方向数组
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
class Solution {
public:
    int n;
    int largestIsland(vector<vector<int>>& g) {
        n=g.size();
        memset(v,-1,sizeof v);
        unordered_map<int,int> area;
        int res=0;
        // 对同一块岛屿的面积进行打标记
        int t=2;
        // 先统计每块岛屿的面积，同时每块岛屿进行打标记
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(g[i][j]==1 and v[i][j]==-1)
                {
                    int cnt=dfs(g,i,j,t);
                    area[t++]=cnt,res=max(res,cnt);
                }
        // 枚举每个水域，然后将它相邻的四个点岛屿面积加进来，因为每个岛屿进行了标记，所以不存在重复记录的情况
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(g[i][j]==0)
                {
                    int cnt=1;
                    unordered_set<int> rec;
                    for(int k=0;k<4;++k){
                        int nx=i+dx[k],ny=j+dy[k];
                        // 下一个点：越界、或不为岛屿、或者与之前的岛屿重复，则不用进行计数了
                        if(nx<0||ny<0||nx>=n||ny>=n||v[nx][ny]==-1||rec.count(v[nx][ny]))continue;
                        cnt+=area[v[nx][ny]],rec.insert(v[nx][ny]);
                    }
                    res=max(res,cnt);
                }
        return res;
    }

    int dfs(vector<vector<int>>& g,int i,int j,int t)
    {
        // 越界、当前点为水域、或者当前点已经被访问过了，直接返回 0
        if(i<0||j<0||i>=n||j>=n||g[i][j]==0||v[i][j]!=-1)return 0;
        // 当前点的面积现为 1，同时标记当前点
        int res=1;v[i][j]=t;
        for(int k=0;k<4;++k)
        {
            int nx=i+dx[k],ny=j+dy[k];
            res+=dfs(g,nx,ny,t);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> g={{1,0},{0,1}};
    cout<<Solution().largestIsland(g)<<endl;
    return 0;
}