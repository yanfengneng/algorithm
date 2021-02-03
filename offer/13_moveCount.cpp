#include <bits/stdc++.h>
using namespace std;

// �ĸ���������
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
// ������顣��ֹ���ظ�����
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
        // �޷�����(i,j)�����
        if(work(i)+work(j)>k)return;
        // ���Ե�(i,j)����㣬����Ǻ�cnt+1
        visited[i][j]=true;   
        cnt++;
        // ����4�������dfs
        for(int c=0;c<4;++c)
        {
            int x=i+dx[c],y=j+dy[c];
            if(x>=0&&x<m&&y>=0&&y<n&&!visited[x][y])
                dfs(m,n,k,x,y,cnt);
        }
    }

    // �������λ֮��
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