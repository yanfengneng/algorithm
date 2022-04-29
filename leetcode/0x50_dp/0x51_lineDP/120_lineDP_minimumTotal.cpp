#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res=1e4+10,n;
    int minimumTotal(vector<vector<int>>& t) {
        n=t.size();
        dfs(t,0,0,0);
        return res;
    }

    void dfs(vector<vector<int>>& t,int x,int y,int sum)
    {
        if(x==n){res=min(res,sum);return;}
        dfs(t,x+1,y,sum+t[x][y]),dfs(t,x+1,y+1,sum+t[x][y]);
    }
};

int main()
{
    vector<vector<int>> t={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<Solution().minimumTotal(t)<<endl;
    return 0;
}