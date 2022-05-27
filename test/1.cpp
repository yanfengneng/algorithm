#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
bool g[N][N];
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& gu, vector<vector<int>>& wa) {
        set<vector<int>> st(wa.begin(),wa.end());
        memset(g,0,sizeof g);
        for(auto p:gu)
        {
            int x=p[0],y=p[1];
            // 往下走
            for(int i=x;i<m;++i)
            {
                if(st.count({i,y}))break;
                g[i][y]=1;
            }
            // 往上走
            for(int i=x;i>=0;i--)
            {
                if(st.count({i,y}))break;
                g[i][y]=1;
            }
            // 往右走
            for(int j=y;j<n;++j)
            {
                if(st.count({x,j}))break;
                g[x][j]=1;
            }
           // 往左走
            for(int j=y;j>=0;--j)
            {
                if(st.count({x,j}))break;
                g[x][j]=1;
            }
        }
        
        int cnt=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(!g[i][j])cnt++;
        return cnt;
    }
};

int main()
{
    vector<vector<int>> gu={{1,1}},wa={{0,1},{1,0},{2,1},{1,2}};
    Solution().countUnguarded(3,3,gu,wa);
    return 0;
}