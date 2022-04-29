#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
class Solution {
public:
    // 写个bfs完事了
    int m,n;
    int numEnclaves(vector<vector<int>>& g) {
        m=g.size(),n=g[0].size();
        int cnt=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(g[i][j])cnt+=bfs(g,i,j);
            }
        }
        return cnt;
    }

    int bfs(vector<vector<int>>& g,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        g[i][j]=0;
        bool flag=false;
        int cnt=1;
        while(q.size()){
            auto [x,y]=q.front();q.pop();
            for(int k=0;k<4;++k){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0||ny<0||nx>=m||ny>=n){flag=true;continue;}
                if(g[nx][ny]==0)continue;
                cnt++;g[nx][ny]=0;q.push({nx,ny});
            }
        }
        return flag?0:cnt;
    }
};

int main()
{
    vector<vector<int>> g= {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    Solution().numEnclaves(g);
    return 0;
}