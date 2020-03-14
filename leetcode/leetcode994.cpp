#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[]={0,-1,0,1},dy[]={-1,0,1,0};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int res=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i)for(int j=0;j<n;++j)if(grid[i][j]==2)q.push({i,j});
        while(!q.empty()){
            int span=q.size();
            for(int i=0;i<span;++i){
                pair<int,int> p=q.front();q.pop();
                for(int j=0;j<4;++j){
                    int x=p.first+dx[j],y=p.second+dy[j];
                    if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            if(!q.empty())res++;
        }
        for(int i=0;i<m;++i)for(int j=0;j<n;++j)if(grid[i][j]==1)return -1;
        return res;
    }
};

int main()
{
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    cout<<Solution().orangesRotting(grid)<<endl;
}