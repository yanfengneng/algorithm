#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
int fa[N],len[N];

// ��ʼ��
void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        len[i]=1;
    }
}

// ��ѯ����������·��ѹ��
int find(int x)
{
    if(fa[x]!=x)return fa[x]=find(fa[x]);
    else return x;
}

// �ϲ�x��y�����ļ��ϣ������Ⱥϲ�
void merge(int x,int y)
{
    x=find(x),y=find(y);
    // x y ����ͬһ�飬���ý��кϲ�
    if(x==y)return;
    // С������Ⱥϲ�
    if(len[x]<len[y])
    {
        fa[x]=y;    // ��x�ĸ��ڵ�ָ��y
        len[y]+=len[x];
    }
    else
    {
        fa[y]=x;    // ��y�ĸ��ڵ�ָ��x
        len[x]+=len[y];
    }
}

int n,m;

int main()
{
    int cnt=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m)break;
        init(n);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        int res=0;
        // ÿ����ͨ���ĸ�ֻ��һ�������Ǳ���n���㣬ͳ�Ƹ��ĸ���������ͨ���ĸ���
        for(int i=1;i<=n;++i)
            if(i==find(i))res++;
    
        printf("Case %d: %d\n",++cnt,res);
    }
    return 0;
}