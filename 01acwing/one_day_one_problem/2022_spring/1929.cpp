#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n,m;
char g[N][N];
// �ĸ�����0���ϣ�1���ң�2���£�3����
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int dfs(int x,int y,int d)
{
    // ����߽磬��ʾ�߳������ˣ����ؾ���0
    if(x<0||y<0||x>=n||y>=m)return 0;

    // ����Ϊб����ʱ��0->1��3->2��2->3��1->0���պ�����ɶԱ任��d^1���ת��
    if(g[x][y]=='/')d^=1;
    // ����Ϊб����ʱ��0->3��1->2��2->1��3->0������d���3�պ���ɱ任
    else d^=3;

    return dfs(x+dx[d],y+dy[d],d)+1;
}

 int main()
 {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",&g[i]);

    int res=0;
    // ö�����е��е����
    for(int i=0;i<n;++i)
    {
        // ���������ߣ�ÿ�еĵ�һ��λ��(i,0)Ϊ��㣬������
        res=max(res,dfs(i,0,1));
        // ���������ߣ�ÿ�е����һ��λ��(i,m-1)Ϊ��㣬������
        res=max(res,dfs(i,m-1,3));
    }

    // ö�������е����
    for(int i=0;i<m;++i)
    {
        // ���������ߣ�ÿ�еĵ�һ��λ��(0,i)Ϊ��㣬������
        res=max(res,dfs(0,i,2));
        // ���������ߣ�ÿ�е����һ��λ��(n-1,i)Ϊ��㣬������
        res=max(res,dfs(n-1,i,0));
    }
    
    printf("%d\n",res);
    return 0;
 }