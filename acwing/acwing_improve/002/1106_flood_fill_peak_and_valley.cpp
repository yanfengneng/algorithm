#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
const int N = 1010;
int h[N][N];
// �������
bool v[N][N];
// ��������
int dx[]={1,0,-1,0,1,-1,1,-1},dy[]={0,1,0,-1,1,-1,-1,1};

int n;

void bfs(int i,int j,bool& f1,bool& f2)
{
    queue<PII> q;
    // ��ʷ����ʵ����������Ӿ�Ҫ����
    q.push({i,j});
    v[i][j]=1;
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int k=0;k<8;++k)
        {
            int nx=x+dx[k],ny=y+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=n)continue;
            // �ҵ�ɽ���ı߽���
            if(h[x][y]!=h[nx][ny])
            {
                if(h[nx][ny]>h[x][y])f1=true;
                else f2=true;
            }
            // ͬ��һ����ͨ�飬��û�б��ظ����ʹ�
            else if(!v[nx][ny])
            {
                q.push({nx,ny});
                v[nx][ny]=1;
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&h[i][j]);

    int peak=0,valley=0;       
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(!v[i][j])
            {
                // f1��ʾ�Ƿ��б������ͨ�����ĵ㣬f2��ʾ�Ƿ��б������ͨ���С�ĵ�
                bool f1=false,f2=false;
                bfs(i,j,f1,f2);
                // �޸���ĵ㣬Ϊɽ��
                if(!f1)peak++;
                // �޸�С�ĵ㣬Ϊɽ��
                if(!f2)valley++;
            }
    printf("%d %d\n",peak,valley);
    return 0;
}