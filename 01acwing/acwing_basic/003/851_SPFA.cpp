#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5+10;

int n,m;

// e[i]=j��ʾi���ڽڵ�Ϊj
int h[N],e[N],ne[N],w[N],idx=0;

// ��̾�������Ͷ���������
int dist[N];
bool flag[N]={0};

// a->b ��ȨֵΪ c
void add(int a,int b,int c)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

// �����Դ��s���������·
int spfa(int s)
{
    // ��ʼ��dist
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    
    // ��ʼ�����к�s����
    // �����д�ŵ��Ǿ����С�ĵ㣬�Ҷ����еĵ㲻���ظ���Ҫ��flag�����
    queue<int> q;
    q.push(s);
    // flag����ǵ�ǰ������Ƿ��ڶ���֮�У���ֹ����֮�д洢�ظ��ĵ�
    flag[s]=true;

    while(!q.empty())
    {
        int t=q.front();
        q.pop();

        // ��t�������ˣ����Ϊfalse
        flag[t]=false;

        // ���� t �������ڱߣ�i->j ��ȨֵΪ w[i]
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            // ���ɳڣ�����и���
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];

                // ��j���ڶ����У���������
                if(!flag[j])
                {
                    q.push(j);
                    flag[j]=true;
                }
            }
        }
    }

    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    // ��ʼ���ڽӱ���
    memset(h,-1,sizeof h);

    scanf("%d%d",&n,&m);

    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }

    int t = spfa(1);

    if(t==-1)puts("impossible");
    else printf("%d\n",t);

    return 0;
}