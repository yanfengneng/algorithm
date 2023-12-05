#include <bits/stdc++.h>
using namespace std;

// �������飺��������
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& g) {
        // ʹ���ַ������洢����״̬
        string start;
        for(int i=0;i<2;i++)for(int j=0;j<3;j++)start+=(g[i][j]+'0');
        // �յ����̵�״̬
        string end="123450";

        // �������к;�������
        queue<string> q;
        unordered_map<string,int> dist;
        // ����������к;�������
        q.push(start),dist[start]=0;

        // ��ʼ���� bfs
        while(q.size())
        {
            auto t=q.front();q.pop();
            // ��ǰ״̬ t �ľ���
            int distance=dist[t];
            // ���� bfs �Ǽ������ʱ�ͽ�״̬�ľ�����и��£���ô��ǰ״̬Ϊ�յ�ʱ��ֱ�ӷ��ؾ���
            if(t==end)return distance;
            // �ַ�'0'��һά�ַ����е����꣬�Լ�ת��Ϊ 2*3 �ľ��������
            int k=t.find('0');
            int x=k/3,y=k%3;

            // ���� 4 �������ö��
            for(int i=0;i<4;++i)
            {
                int nx=x+dx[i],ny=y+dy[i];
                // �ж��Ƿ�Խ�磬Խ��ֱ������
                if(nx<0||ny<0||nx>1||ny>2)continue;
                // (nx,ny)��һά�ַ����е�����Ϊ nx*3+ny
                // ����״̬
                swap(t[k],t[nx*3+ny]);
                // ����չ����״̬û�б����ʹ�������µ���״̬�ľ��룬���������
                if(!dist.count(t)){
                    q.push(t),dist[t]=distance+1;
                }
                // �ָ�״̬
                swap(t[k],t[nx*3+ny]);
            }
        }

        // ����δ�����յ�״̬������ -1
        return -1;
    }
};

int main()
{
    vector<vector<int>> g={{1,2,3},{5,4,0}};
    cout<<Solution().slidingPuzzle(g)<<endl;
    return 0;
}