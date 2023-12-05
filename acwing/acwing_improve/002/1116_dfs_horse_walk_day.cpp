#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N = 10;
// ������飬��ֹ�㱻�ظ�����
bool v[N][N];
// �������飺8������
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={-2,-1,1,2,2,1,-1,-2};

int res;
// ����cnt��ʾ����������cnt���㣬�ܹ���n*m����
void dfs(int x,int y,int cnt)
{
    if(cnt==n*m)// ��ʾ�ҵ�һ�������������Ը÷������м���
    {
        res++;
        return;
    }
    // ��Ǹõ��Ѿ���������
    v[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        // Խ�����Ѿ������ʹ��ĵ��������
        if(nx<0 || nx>=n || ny<0 || ny>=m || v[nx][ny])continue;
        // �´η��ʵ�cnt+1����
        dfs(nx,ny,cnt+1);
    }
    // �ָ��ֳ������ڽ�����һ����֧
    v[x][y]=0;
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        res=0;
        int x,y;
        scanf("%d%d%d%d",&n,&m,&x,&y);
        dfs(x,y,1);
        printf("%d\n",res);
    }
    return 0;
}