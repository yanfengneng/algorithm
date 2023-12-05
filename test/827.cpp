#include <bits/stdc++.h>
using namespace std;

const int N = 510;
// �������
int v[N][N];
// ��������
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
class Solution {
public:
    int n;
    int largestIsland(vector<vector<int>>& g) {
        n=g.size();
        memset(v,-1,sizeof v);
        unordered_map<int,int> area;
        int res=0;
        // ��ͬһ�鵺���������д���
        int t=2;
        // ��ͳ��ÿ�鵺��������ͬʱÿ�鵺����д���
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(g[i][j]==1 and v[i][j]==-1)
                {
                    int cnt=dfs(g,i,j,t);
                    area[t++]=cnt,res=max(res,cnt);
                }
        // ö��ÿ��ˮ��Ȼ�������ڵ��ĸ��㵺������ӽ�������Ϊÿ����������˱�ǣ����Բ������ظ���¼�����
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(g[i][j]==0)
                {
                    int cnt=1;
                    unordered_set<int> rec;
                    for(int k=0;k<4;++k){
                        int nx=i+dx[k],ny=j+dy[k];
                        // ��һ���㣺Խ�硢��Ϊ���졢������֮ǰ�ĵ����ظ������ý��м�����
                        if(nx<0||ny<0||nx>=n||ny>=n||v[nx][ny]==-1||rec.count(v[nx][ny]))continue;
                        cnt+=area[v[nx][ny]],rec.insert(v[nx][ny]);
                    }
                    res=max(res,cnt);
                }
        return res;
    }

    int dfs(vector<vector<int>>& g,int i,int j,int t)
    {
        // Խ�硢��ǰ��Ϊˮ�򡢻��ߵ�ǰ���Ѿ������ʹ��ˣ�ֱ�ӷ��� 0
        if(i<0||j<0||i>=n||j>=n||g[i][j]==0||v[i][j]!=-1)return 0;
        // ��ǰ��������Ϊ 1��ͬʱ��ǵ�ǰ��
        int res=1;v[i][j]=t;
        for(int k=0;k<4;++k)
        {
            int nx=i+dx[k],ny=j+dy[k];
            res+=dfs(g,nx,ny,t);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> g={{1,0},{0,1}};
    cout<<Solution().largestIsland(g)<<endl;
    return 0;
}