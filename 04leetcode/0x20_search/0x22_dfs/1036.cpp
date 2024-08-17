#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
// 方向数组
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
using PII = pair<int,int>;
class Solution {
public:
    vector<int> hx,hy;
    unordered_map<int,int> mpx,mpy;
    // 离散化后数组的大小
    int m,n;
    // 路障点+起点+终点最多有202个点，x y坐标每个前后留空后最多各自有606个点
    // 这样的话 dfs只用在606*606的图中进行搜索了
    bool visited[606][606];
    // 将x坐标加入hx中，同时将x坐标的前后留空
    void help_x(int x){
        hx.push_back(x);
        if(x)hx.push_back(x-1);
        if(x+1<N)hx.push_back(x+1);
    }
    // 将y坐标加入hy中，同时将y坐标的前后留空
    void help_y(int y){
        hy.push_back(y);
        if(y)hy.push_back(y-1);
        if(y+1<N)hy.push_back(y+1);
    }

    // dfs：从起点搜终点即可
    bool dfs(int x,int y,int &tx,int &ty){
        if(x==tx&&y==ty)return true;
        //if(x<0||x==m||y<0||y==n||visited[x][y])return false;
        visited[x][y]=true;
        //bool flag=false;
        for(int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            /*这种带返回值类型的dfs：要是遇到边界或者访问过的点，该层的flag为false，那么dfs返回false，这样写也不会错
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!visited[nx][ny])
                flag|=dfs(nx,ny,tx,ty);*/
            // 下面这种进入dfs的判断 代码执行会更快一些
            if(nx<0||ny<0||nx==m||ny==n||visited[nx][ny])continue;
            if(dfs(nx,ny,tx,ty))return true;
        }
        return false;
    }
    // bfs：从离散化后的起点搜终点即可
    bool bfs(int x,int y,int tx,int ty){
        queue<PII> q;
        q.push({x,y});
        visited[x][y]=true;
        while(q.size()){
            auto [k,v]=q.front();q.pop();
            for(int i=0;i<4;++i){
                int nx=k+dx[i],ny=v+dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&!visited[nx][ny]){
                    if(nx==tx&&ny==ty)return true;
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }
    // 思路：离散化+dfs，具体思路写在博客中了
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty())return true;
        // 1、离散化路障、起点、终点
        for(auto b:blocked){
            help_x(b[0]),help_y(b[1]);
        }
        help_x(source[0]),help_y(source[1]);
        help_x(target[0]),help_y(target[1]);
        // 2、排序去重
        sort(hx.begin(),hx.end());
        sort(hy.begin(),hy.end());
        m=unique(hx.begin(),hx.end())-hx.begin();// hx中只有m个不同的元素值，其余为重复值
        n=unique(hy.begin(),hy.end())-hy.begin();// hy中只有n个不同的元素值，其余为重复值
        // 3、将x坐标的m个不同的元素进行映射为[0,m-1]之间的数字，将y坐标的n个不同的元素进行映射为[0,n-1]之间的数字
        for(int i=0;i<m;++i){
            mpx[hx[i]]=i;
            // 每个行的n个元素进行初始化
            memset(visited[i],0,n);
        }
        for(int i=0;i<n;++i){
            mpy[hy[i]]=i;
        }
        // 4、将离散化的路障做打标记处理，这样在dfs时不能通过这些点
        for(auto b:blocked){
            visited[mpx[b[0]]][mpy[b[1]]]=true;
        }
        // 5、使用离散化的起点搜索离散化的终点
        //return dfs(mpx[source[0]],mpy[source[1]],mpx[target[0]],mpy[target[1]]);
        // 5、使用离散化的起点bfs离散化的终点也是可以的
        return bfs(mpx[source[0]],mpy[source[1]],mpx[target[0]],mpy[target[1]]);
    }
};

int main()
{
    vector<vector<int>> blocked={{691938,300406},{710196,624190},{858790,609485},{268029,225806},{200010,188664},{132599,612099},{329444,633495},{196657,757958},{628509,883388}};
    vector<int> source={655988,180910}, target={267728,840949};
    cout<<Solution().isEscapePossible(blocked,source,target)<<endl;
    return 0;
}