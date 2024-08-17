#include <bits/stdc++.h>
using namespace std;

char g[2][4];
#define x first
#define y second
unordered_map<string,int> dist;
// ��¼��ǰ��������һ������ת�ƹ�����
unordered_map<string,pair<char,string>> pre;

// ����ǰ״̬��������g��
void Set(string state)
{
    for(int i=0;i<4;++i)g[0][i]=state[i];
    // i�Ӻ���ǰ���д洢
    for(int i=7,j=0;j<4;--i,++j)g[1][j]=state[i];
}

// ��õ�ǰ״̬�Ķ�Ӧ���ַ���
string get()
{
    string res;
    for(int i=0;i<4;++i)res+=g[0][i];
    for(int i=3;i>=0;--i)res+=g[1][i];
    return res;
}

// һ���л���
string move0(string state)
{
    Set(state);
    for(int j=0;j<4;++j)swap(g[0][j],g[1][j]);
    return get();
}

// �����в嵽��һ��
string move1(string state)
{
    Set(state);
    char v0=g[0][3],v1=g[1][3];
    // �Ӻ���ǰ��ʼ���и���
    for(int i=3;i>=1;--i){
        g[0][i]=g[0][i-1];
        g[1][i]=g[1][i-1];
    }
    g[0][0]=v0,g[1][0]=v1;
    return get();
}

// �м����˳ʱ����ת
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
    // ���еĳ�ʼ��
    queue<string> q;
    q.push(start);dist[start]=0;

    // ��ʼ����bfs
    while(q.size())
    {
        auto t=q.front();q.pop();
        // ÿ��������ѡ��·��������������֧
        string m[]={move0(t),move1(t),move2(t)};
        //cout<<m[0]<<" "<<m[1]<<" "<<m[2]<<endl;
        for(int i=0;i<3;++i)
        {
            // ��״̬���ܱ����ʹ�
            if(dist.count(m[i]))continue;
            // ת�Ƶ�m[i]�Ĳ������и���
            dist[m[i]]=dist[t]+1;
            // m[i]����״̬t����ת�ƹ�����
            pre[m[i]]={'A'+i,t};
            // ������
            q.push(m[i]);
            // �����յ��ˣ����ص����յ�Ĳ���
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
    // ���յ㿪ʼ��Ѱ�ҵ����
    while(end!=start){
        res+=pre[end].x;
        end=pre[end].y;// ���ǰһ��
    }
    // ��ת�õ���㵽�յ��·��
    reverse(res.begin(),res.end());
    if(step>0)cout<<res<<endl;
    return 0;
}