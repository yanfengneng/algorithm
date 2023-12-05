#include <bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
using PII = pair<int,int>;
class Solution {
public: 
    // 思路1：bfs
    vector<vector<int>> floodFill_1(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int cur=image[sr][sc];
        if(newColor==cur)return image;
        queue<PII> q;
        // 起点进队列
        image[sr][sc]=newColor;
        q.push({sr,sc});
        // 开始bfs
        while(q.size()){
            auto [x,y]=q.front();q.pop();
            for(int i=0;i<4;++i){
                int mx=x+dir[i][0],my=y+dir[i][1];
                if(mx<0||my<0||mx>=image.size()||my>=image[0].size())continue;
                // 已染色的或者与起点颜色不一样的，不需要再次染色了
                if(image[mx][my]==newColor||image[mx][my]!=cur)continue;
                image[mx][my]=newColor;
                q.push({mx,my});
            }
        }
        return image;
    }

    // 思路2：dfs
    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int newColor){
        int cur=image[sr][sc];
        if(cur==newColor)return image;
        dfs(image,sr,sc,newColor,cur);
        return image;
    }

    void dfs(vector<vector<int>>& image,int x,int y,int newColor,int cur){
        // 进行染色
        image[x][y]=newColor;
        for(int i=0;i<4;++i){
            int mx=x+dir[i][0],my=y+dir[i][1];
            if(mx<0||my<0||mx>=image.size()||my>=image[0].size())continue;
            // 已染色或者与起始坐标不相连，不需要进行染色
            if(image[mx][my]==newColor||image[mx][my]!=cur)continue;
            dfs(image,mx,my,newColor,cur);
        }
    }
};

int main()
{
    vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};
    auto i=Solution().floodFill(image,1,1,2);
    return 0;
}