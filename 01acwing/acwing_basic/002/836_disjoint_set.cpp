#include <iostream>
using namespace std;

const int N = 1e5+10;
int fa[N],rk[N];

//  ��ʼ��n��Ԫ��
void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        // rk��ʾ���ĸ߶�
        rk[i]=0;
    }
}

// ��ѯx�ĸ�
int find(int x)
{
    if(fa[x]==x)return x;
    // �ڲ�ѯ���ڵ�Ĺ�����˳������·��ѹ��
    else return fa[x]=find(fa[x]);
}

// �ϲ�x��y�����ļ���
void merge(int x,int y)
{
    // ���ҵ�x��y����Ӧ�ĸ���Ȼ���ж��ǲ���ͬһ���ϣ��ڽ��кϲ����
    x=find(x),y=find(y);
    if(x==y)return;
    // ���а��Ⱥϲ���С��������ϲ�
    if(rk[x]<rk[y])fa[x]=y;
    else
    {
        fa[y]=x;
        // x��y�ĸ߶���ͬ����ϲ�֮��߶�+1
        if(rk[x]==rk[y])rk[x]++;
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    // ���г�ʼ��
    init(n);

    char op[2];
    int a,b;
    while(m--)
    {
        scanf("%s%d%d",op,&a,&b);
        if(op[0]=='M')merge(a,b);
        else
        {
            if(find(a)==find(b))printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}