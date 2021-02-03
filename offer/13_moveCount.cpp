#include <bits/stdc++.h>
using namespace std;

// 四个方向数组
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
// 标记数组。防止点重复访问
bool visited[110][110];

class Solution {
public:
    int movingCount(int m, int n, int k) {
        memset(visited,0,sizeof visited);
        int cnt=0;
        dfs(m,n,k,0,0,cnt);
        return cnt;
    }

    void dfs(int m,int n,int k,int i,int j,int& cnt)
    {
        // 无法到达(i,j)这个点
        if(work(i)+work(j)>k)return;
        // 可以到(i,j)这个点，则打标记和cnt+1
        visited[i][j]=true;   
        cnt++;
        // 进行4个方向的dfs
        for(int c=0;c<4;++c)
        {
            int x=i+dx[c],y=j+dy[c];
            if(x>=0&&x<m&&y>=0&&y<n&&!visited[x][y])
                dfs(m,n,k,x,y,cnt);
        }
    }

    // 计算各数位之和
    int work(int x)
    {
        int val=0;
        while(x)val+=x%10,x/=10;
        return val;
    }
};

int main()
{
    cout<<Solution().movingCount(7,2,3)<<endl;
    
}