#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
// ��������
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
using PII = pair<int,int>;
class Solution {
public:
    vector<int> hx,hy;
    unordered_map<int,int> mpx,mpy;
    // ��ɢ��������Ĵ�С
    int m,n;
    // ·�ϵ�+���+�յ������202���㣬x y����ÿ��ǰ�����պ���������606����
    // �����Ļ� dfsֻ����606*606��ͼ�н���������
    bool visited[606][606];
    // ��x�������hx�У�ͬʱ��x�����ǰ������
    void help_x(int x){
        hx.push_back(x);
        if(x)hx.push_back(x-1);
        if(x+1<N)hx.push_back(x+1);
    }
    // ��y�������hy�У�ͬʱ��y�����ǰ������
    void help_y(int y){
        hy.push_back(y);
        if(y)hy.push_back(y-1);
        if(y+1<N)hy.push_back(y+1);
    }

    // dfs����������յ㼴��
    bool dfs(int x,int y,int &tx,int &ty){
        if(x==tx&&y==ty)return true;
        //if(x<0||x==m||y<0||y==n||visited[x][y])return false;
        visited[x][y]=true;
        //bool flag=false;
        for(int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            /*���ִ�����ֵ���͵�dfs��Ҫ�������߽���߷��ʹ��ĵ㣬�ò��flagΪfalse����ôdfs����false������дҲ�����
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!visited[nx][ny])
                flag|=dfs(nx,ny,tx,ty);*/
            // �������ֽ���dfs���ж� ����ִ�л����һЩ
            if(nx<0||ny<0||nx==m||ny==n||visited[nx][ny])continue;
            if(dfs(nx,ny,tx,ty))return true;
        }
        return false;
    }
    // bfs������ɢ�����������յ㼴��
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
    // ˼·����ɢ��+dfs������˼·д�ڲ�������
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty())return true;
        // 1����ɢ��·�ϡ���㡢�յ�
        for(auto b:blocked){
            help_x(b[0]),help_y(b[1]);
        }
        help_x(source[0]),help_y(source[1]);
        help_x(target[0]),help_y(target[1]);
        // 2������ȥ��
        sort(hx.begin(),hx.end());
        sort(hy.begin(),hy.end());
        m=unique(hx.begin(),hx.end())-hx.begin();// hx��ֻ��m����ͬ��Ԫ��ֵ������Ϊ�ظ�ֵ
        n=unique(hy.begin(),hy.end())-hy.begin();// hy��ֻ��n����ͬ��Ԫ��ֵ������Ϊ�ظ�ֵ
        // 3����x�����m����ͬ��Ԫ�ؽ���ӳ��Ϊ[0,m-1]֮������֣���y�����n����ͬ��Ԫ�ؽ���ӳ��Ϊ[0,n-1]֮�������
        for(int i=0;i<m;++i){
            mpx[hx[i]]=i;
            // ÿ���е�n��Ԫ�ؽ��г�ʼ��
            memset(visited[i],0,n);
        }
        for(int i=0;i<n;++i){
            mpy[hy[i]]=i;
        }
        // 4������ɢ����·�������Ǵ���������dfsʱ����ͨ����Щ��
        for(auto b:blocked){
            visited[mpx[b[0]]][mpy[b[1]]]=true;
        }
        // 5��ʹ����ɢ�������������ɢ�����յ�
        //return dfs(mpx[source[0]],mpy[source[1]],mpx[target[0]],mpy[target[1]]);
        // 5��ʹ����ɢ�������bfs��ɢ�����յ�Ҳ�ǿ��Ե�
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