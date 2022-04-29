#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 题目给的是邻接矩阵，然后判断邻接矩阵中的连通块的个数
    bool visited[400];
    int n,cnt;
    int findCircleNum(vector<vector<int>>& g) {
        memset(visited,0,sizeof visited);
        n=g.size(),cnt=0;
        // 从顶点i开始寻找连通量
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(g,i);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& g,int i){
        // 遍历 i 的所有邻接点
        for(int j=0;j<n;++j){
            if(g[i][j]&&!visited[j]){
                visited[j]=true;
                dfs(g,j);
            }
        }
    }
};

int main()
{
    vector<vector<int>> g= {{1,1,0},{1,1,0},{0,0,1}};
    cout<<Solution().findCircleNum(g)<<endl;
    return 0;
}