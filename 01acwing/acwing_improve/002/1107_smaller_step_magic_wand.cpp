#include <bits/stdc++.h>
using namespace std;

char g[2][4];
#define x first
#define y second
unordered_map<string,int> dist;
// 记录当前步是由上一步进行转移过来的
unordered_map<string,pair<char,string>> pre;

// 将当前状态存在数组g中
void Set(string state)
{
    for(int i=0;i<4;++i)g[0][i]=state[i];
    // i从后往前进行存储
    for(int i=7,j=0;j<4;--i,++j)g[1][j]=state[i];
}

// 获得当前状态的对应的字符串
string get()
{
    string res;
    for(int i=0;i<4;++i)res+=g[0][i];
    for(int i=3;i>=0;--i)res+=g[1][i];
    return res;
}

// 一二行互换
string move0(string state)
{
    Set(state);
    for(int j=0;j<4;++j)swap(g[0][j],g[1][j]);
    return get();
}

// 第四列插到第一列
string move1(string state)
{
    Set(state);
    char v0=g[0][3],v1=g[1][3];
    // 从后往前开始进行覆盖
    for(int i=3;i>=1;--i){
        g[0][i]=g[0][i-1];
        g[1][i]=g[1][i-1];
    }
    g[0][0]=v0,g[1][0]=v1;
    return get();
}

// 中间进行顺时针旋转
string move2(string state)
{
    Set(state);
    int v = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = v;
    return get();
}

int bfs(string start,string end)
{
    if(start==end)return 0;
    // 队列的初始化
    queue<string> q;
    q.push(start);dist[start]=0;

    // 开始进行bfs
    while(q.size())
    {
        auto t=q.front();q.pop();
        // 每次有三种选择路径，即有三个分支
        string m[]={move0(t),move1(t),move2(t)};
        //cout<<m[0]<<" "<<m[1]<<" "<<m[2]<<endl;
        for(int i=0;i<3;++i)
        {
            // 该状态不能被访问过
            if(dist.count(m[i]))continue;
            // 转移到m[i]的步数进行更新
            dist[m[i]]=dist[t]+1;
            // m[i]是由状态t进行转移过来的
            pre[m[i]]={'A'+i,t};
            // 进队列
            q.push(m[i]);
            // 到达终点了，返回到达终点的步数
            if(m[i]==end)return dist[end];
        }
    }
    return -1;
}

int main()
{
    string start,end;
    for(int i=1;i<=8;++i)start+=char('0'+i);
    int x;
    for(int i=0;i<8;++i){
        cin>>x;
        end+=char('0'+x);
    }

    int step=bfs(start,end);
    cout<<step<<endl;

    string res;
    // 从终点开始逐步寻找到起点
    while(end!=start){
        res+=pre[end].x;
        end=pre[end].y;// 获得前一步
    }
    // 反转得到起点到终点的路径
    reverse(res.begin(),res.end());
    if(step>0)cout<<res<<endl;
    return 0;
}