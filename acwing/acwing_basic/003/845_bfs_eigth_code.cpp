#include <bits/stdc++.h>
using namespace std;

// �������飺��������
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int bfs(string start)
{
    // ʹ���ַ�������ʾ���̵�״̬
    // �������к;�������
    queue<string> q;
    unordered_map<string,int> dist;
    // ����������к;�������
    q.push(start),dist[start]=0;
    // �յ��״̬
    string end="12345678x";

    // ��ʼ���� BFS
    while(q.size())
    {
        auto t=q.front();q.pop();
        // ״̬ t �ľ���
        int distance=dist[t];
        // ���� bfs �Ǽ������ʱ�ͽ�״̬�ľ�����и��£���ô��ǰ״̬Ϊ�յ�ʱ��ֱ�ӷ��ؾ���
        if(t==end)return distance;

        // �ַ�'x'��һά�ַ����е������Լ���Ӧ3*3�����е�����
        int k=t.find('x');
        int x=k/3,y=k%3;

        // ��ʼ���� 4 �������״̬ת��
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            // ����Խ�磬��ֱ������
            if(nx<0||ny<0||nx>2||ny>2)continue;
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
    // ���е�״̬�����󣬻�δ�ҵ����մ𰸣����� -1
    return -1;
}

int main()
{
    string start;
    for(int i=0;i<9;++i){
        char c;cin>>c;
        start+=c;
    }

    printf("%d\n",bfs(start));
    return 0;
}