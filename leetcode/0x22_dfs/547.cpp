#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ��Ŀ�������ڽӾ���Ȼ���ж��ڽӾ����е���ͨ��ĸ���
    bool visited[400];
    int n,cnt;
    int findCircleNum(vector<vector<int>>& g) {
        memset(visited,0,sizeof visited);
        n=g.size(),cnt=0;
        // �Ӷ���i��ʼѰ����ͨ��
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(g,i);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& g,int i){
        // ���� i �������ڽӵ�
        for(int j=0;j<n;++j){
            if(g[i][j]&&!visited[j]){
                visited[j]=true;
                dfs(g,j);
            }
        }
    }
};

int main()
{
    vector<vector<int>> g= {{1,1,0},{1,1,0},{0,0,1}};
    cout<<Solution().findCircleNum(g)<<endl;
    return 0;
}