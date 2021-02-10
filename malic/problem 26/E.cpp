#include <iostream>
#include <cstring>
using namespace std;

// Longset[i][j]��ʾ��(i,j)����ݶ��½��ĳ���
int g[110][110],longest[110][110];

int n,m;
// ��������
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int dfs(int i,int j)
{
    // ��(i,j)������³����ҵ���ֱ�ӷ���
    if(longest[i][j])return longest[i][j];
    // ÿ���㶼��ʾһ������
    int cnt=1;
    for(int k=0;k<4;++k)
    {
        int x=i+dx[k],y=j+dy[k];
        if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]<g[i][j])
        {
            // ÿ����һ���㣬�����+1
            cnt=max(cnt,dfs(x,y)+1);
        }
    }
    return longest[i][j]=cnt;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;++j)
            cin>>g[i][j];
    
    int res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;++j)
        {
            res=max(res,dfs(i,j));
        }
    
    cout<<res<<endl;
    return 0;
}