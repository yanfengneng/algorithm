#include <bits/stdc++.h>
using namespace std;

// ���벻�ÿ�������ֻ���ȼ��ٳ�2�ͺ���
const int N = 1e5+10;
int dist[N];
int n,k;

int bfs()
{
    // ��ʼ�����������Ѿ����У�������������к;���������
    memset(dist,-1,sizeof dist);
    queue<int> q;
    q.push(n);
    dist[n]=0;
    // �����еĵ㵽���ľ���һ���ǵ����ģ���Ϊ������һ��һ��Ľ�����չ�ģ����Ե�һ���ҵ��յ�ľ���һ������̾���
    while(q.size())
    {
        int t=q.front();q.pop();
        // �ߵ��յ���
        if(t==k)return dist[k];
        // �����б�ȨΪ1��δ���ʹ��Ķ����������У���������̾���
        if(t+1<N&&dist[t+1]==-1){
            dist[t+1]=dist[t]+1;
            q.push(t+1);
        }
        if(t-1>=0&&dist[t-1]==-1){
            dist[t-1]=dist[t]+1;
            q.push(t-1);
        }
        if(t*2<N&&dist[t*2]==-1){
            dist[t*2]=dist[t]+1;
            q.push(t*2);
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&n,&k);
    printf("%d\n",bfs());
    return 0;
}