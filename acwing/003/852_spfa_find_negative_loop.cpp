#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5+10;

int n,m;

// e[i]=j��ʾi���ڽڵ�Ϊj
int h[N],e[N],ne[N],w[N],idx=0;

// ��̾�������Ͷ���������
// cnt��ʾ��ǰ���·�ĳ���
int dist[N],cnt[N];
bool flag[N]={0};

// a->b ��ȨֵΪ c
void add(int a,int b,int c)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}


bool spfa()
{
    // ��ʼ��dist
    memset(dist,0,sizeof dist);
    
    queue<int> q;
    // ���ڸ�����һ���Ǵ�1�ŵ㿪ʼ�ģ�ÿ���㶼�п��ܣ����԰�ÿ���㶼���ڶ�������
    for(int i=1;i<=n;++i)
    {
        flag[i]=true,q.push(i);
    }

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
                // ÿ�θ��£�ͬʱ����cnt
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;

                // ���·�����ȴ��ڵ���n�ˣ���ʾ���ڸ�����
                // �������n����Ȼ�����ˣ�����ڸ���
                if(cnt[j]>=n)return true;
                // ��j���ڶ����У���������
                if(!flag[j])
                {
                    q.push(j);
                    flag[j]=true;
                }
            }
        }
    }

    return false;
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

    if(spfa())puts("Yes");
    else puts("No");

    return 0;
}