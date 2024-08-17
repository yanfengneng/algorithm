#include <iostream>
#include <cstring>
using namespace std;

const int N =1e5+10;
// �ڽӱ�
int h[N],e[N],ne[N],idx=0;
// ����Ͷ���
int dist[N],q[N];

int n,m;

void add(int a,int b)
{
    // ͷ�巨
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int bfs()
{
    // tt������ʼ��Ϊ-1�ģ���ΪҪ��1�ŵ������У�Ȼ���Ϊ0��
    // ttΪ��β�ǿ�Ԫ��
    int tt=0,hh=0;
    q[0]=1;

    // ��ʼ�����룬-1��ʾû�б�������
    memset(dist,-1,sizeof dist);
    // 1�ŵ�ľ���Ϊ0
    dist[1]=0;
    
    // ��ʼbfs
    while(hh<=tt)
    {
        // ȡ��ͷԪ�أ�������ͷԪ�س�����
        int t=q[hh++];

        for(int i=h[t];i!=-1;i=ne[i])
        {
            // j ��ʾ��ǰ����Ե��ĵ�
            int j = e[i];
            // �� j �ŵ�û�б���չ���Ļ�������չһ��
            if(dist[j]==-1)
            {
                // ���²���
                dist[j]=dist[t]+1;
                // �������
                q[++tt]=j;
            }
        }
    }
    return dist[n];
}

int main()
{
    cin>>n>>m;
    // ��ʼ���ٽ���ͷ�ڵ�
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        // ����Ϊ����ͼ
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}