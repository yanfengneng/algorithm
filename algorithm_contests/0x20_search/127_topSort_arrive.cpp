#include <iostream>
#include <bitset>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3e4+10;

// �ڽӱ�e����ǵ��ڽڵ㣬ne��ŵ����ڽڵ�Ľڵ�id��idxΪ��ǰ���õĽڵ�id
int h[N],e[N],ne[N],idx=1;

// ��������
int d[N],skt[N];

// f(x)��ʾ��iλΪ1��ʾx�ܵ�i�㣬0��ʾ���ܵ�i��
bitset<N> f[N];

int n,m;

void add(int a,int b)
{
    // ͷ�巨
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void topsort()
{
    queue<int> q;
    // ����Ϊ0�ĵ�������
    for(int i=1;i<=n;++i)
        if(!d[i])q.push(i);

    int k=0;
    // ��ʼbfs
    while(!q.empty())
    {
        // ���Ϊ0�ĵ�����У�ҲΪtopsort�ĵ㣬����stk
        int t=q.front();q.pop();
        skt[k++]=t;
        // ɾ��tָ������бߣ����ڽڵ�����-1��Ϊ0ʱ�������
        for(int i=h[t];i;i=ne[i])
        {
            int j=e[i];
            if(--d[j]==0)q.push(j);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    // ����0��ʼ���Ļ���idxҪ��1��ʼ�����idx��0��ʼ�Ļ����ͻᷢ��������Ϊ0��Ϊ�ڵ��ţ�����Ϊ�����ı�ֵ��ͻ�ˣ�����Ҫ��0��ʼ��
    // ����-1��ʼ���Ļ���������-1��Ϊ�����ı�ֵ��idx��0��ʼ��Ϊ�ڵ�ı�ţ��������ᷢ����ͻ��
    // �� h ��ʼ��Ϊ -1��idx=0��h ��ʼ��Ϊ0��idx=1�������ڱ����ڽڵ��ʱ��forѭ��������ʱ�򣬲Ų��ᷢ����ͻ��
    memset(h,0,sizeof h);

    for(int i=0;i<m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        d[y]++;
    }
    // ����topsort
    topsort();

    // ���topsort�����ǵ����������f[x]
    for(int i=n-1;i>=0;--i)
    {
        // ���ڿ��ܴ����رߣ����������x����Ϊ0
        int x=skt[i];
        // �Լ����Ե��Լ������Ե���Ϊ1
        f[x][x]=1;
        // ���� x ���ڽڵ㣬�����ǴӺ���ǰ�����ģ����Ժ��涥���f�����Ѿ�������
        // ��x->y�������ȼ������f[y]��Ȼ�����ǴӺ���ǰ������xʱ�����ǰ�x����㲢��f[y]
        // �� {x}��{f[y]}��{����x���ڽڵ�}������x�ܵ�������е���
        for(int k=h[x];k;k=ne[k])
            f[x]|=f[e[k]];
    }

    for(int i=1;i<=n;i++)printf("%d\n",f[i].count());
    return 0;
}