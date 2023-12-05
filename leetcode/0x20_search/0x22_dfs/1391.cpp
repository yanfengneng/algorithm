#include <bits/stdc++.h>
using namespace std;

int g[1010][1010];
bool v[1010][1010];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
class Solution {
public:
    void change(int x,int y,int u)
    {
        g[x][y]=1;
        if(u==1)g[x][y-1]=g[x][y+1]=1;
        else if(u==2)g[x-1][y]=g[x+1][y]=1;
        else if(u==3)g[x-1][y-1]=g[x-1][y]=1;
        else if(u==4)g[x-1][y]=g[x-1][y+1]=1;
        else if(u==5)g[x+1][y]=g[x+1][y-1]=1;
        else if(u==6)g[x+1][y]=g[x+1][y+1]=1;
    }
    // 将每个格子扩展成3*3的方格阵
    bool hasValidPath(vector<vector<int>>& a) {
        memset(g,0,sizeof g),memset(v,0,sizeof v);
        int n=a.size()*3,m=a[0].size()*3;
        for(int i=1;i<n;i+=3)
            for(int j=1;j<m;j+=3){
                cout<<i/3<<" "<<j/3<<endl;
                change(i,j,a[i/3][j/3]);
                
            }
        
        function<bool(int,int)> dfs=[&](int x,int y)->bool{
            if(x==n-1 and y==m-1)return true;
            v[x][y]=1;
            for(int i=0;i<4;++i)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m || v[nx][ny] || !g[nx][ny])continue;
                if(dfs(nx,ny))return true;
            }
            return false;
        };
        return dfs(1,1);
    }
};

int main()
{
    vector<vector<int>> a={{2,4,3},{6,5,2}};
    cout<<Solution().hasValidPath(a)<<endl;
    return 0;
}