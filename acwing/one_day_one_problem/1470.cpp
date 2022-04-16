#include <bits/stdc++.h>
using namespace std;

char s[15][15];
int dist[15][15];
using PII = pair<int,int>;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int bfs()
{
    memset(dist,-1,sizeof dist);
    queue<PII> q;
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j)
            if(s[i][j]=='B'){
                q.push({i,j});
                dist[i][j]=0;
            }
    }
    // 开始 bfs
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<10&&ny<10&&dist[nx][ny]==-1&&s[nx][ny]!='R'){
                if(s[nx][ny]=='L')return dist[x][y];
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}

// 思路2：bfs
int main()
{
    for(int i=0;i<10;++i)scanf("%s",s[i]);
    
    cout<<bfs()<<endl;
   
    return 0;
}