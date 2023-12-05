#include <iostream>
#include <algorithm>
using namespace std;

int n,m;

const int N = 2e5+10;
int fa[N];

// �ýṹ���ÿ���ߴ�����
struct Edge
{   
    int a,b,w;

    // ����һ��С�ںţ�������������
    bool operator < (const Edge& W)const
    {
        return w<W.w;
    }
}edges[N];

int  find(int x)
{
    if(x!=fa[x])return fa[x]=find(fa[x]);
    else return x;
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;++i)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }

    // �������б�
    sort(edges,edges+m);

    // ��ʼ�����鼯
    for(int i=1;i<=n;++i)fa[i]=i;

    // resΪ��С��������Ȩ�أ�cnt������С�������ı���
    int res=0,cnt=0;

    // ö��һ��ÿ����
    for(int i=0;i<m;++i)
    {
        int a=edges[i].a, b=edges[i].b, w=edges[i].w;

        // �ж�a��b�Ƿ��������ò�ͬ����
        a=find(a),b=find(b);

        if(a!=b)
        {
            // �ϲ�������
            fa[a]=b;
            res+=w;
            cnt++;
        }
    }

    if(cnt<n-1)puts("impossible");
    else printf("%d\n",res);

    return 0;
}