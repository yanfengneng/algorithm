#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int h[N][N];
// ״̬f[i][j]=c��ʾ��(i,j)��ʼ����·��ֵ��Ҳ��������ƽʱд�ļ��仯����
int f[N][N];
// ��������
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m;

// �õݹ�ķ�ʽʵ��״̬ת�ƣ�Ҳ���Ƕ�̬�滮���Զ����½ⷨ--���仯����
int dp(int x,int y)
{
    // ��״̬�ѱ����㣬ֱ�ӷ���
    if(f[x][y]!=-1)return f[x][y];
    // ��(x,y)��ʼ����״̬ת�ƣ����(x,y)��·��ֵΪ1
    f[x][y]=1;
    // ��ʼ�ĸ������״̬ת��
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        // ת�Ƶ��ĵ���ҪûԽ�磬����ת�Ƶ�ĸ߶�ҪС�ڵ�ǰ��ĸ߶ȣ����ܽ���ת�ƣ�ʹ��dp()���õ�(nx,ny)��·��ֵ
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&h[nx][ny]<h[x][y])
            f[x][y]=max(f[x][y],dp(nx,ny)+1);
    }
    // ��������ת�Ƶõ������·��ֵ
    return f[x][y];
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>h[i][j];
    // ��ʼ��״̬���飬����ʾÿ���㶼û�б����
    memset(f,-1,sizeof f);
    int res=0;
    // ö�ٴ�ÿ������������·��ֵ��ֻ����dp(i,j)�ķ���ֵ����������״̬����·��ֵ������ֱ�ӵ���f[i][j]����Ϊf[i][j]��û�б������
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            res=max(res,dp(i,j));
    cout<<res<<endl;
    return 0;
}