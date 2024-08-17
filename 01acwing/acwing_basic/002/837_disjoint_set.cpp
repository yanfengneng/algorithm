#include <iostream>
using namespace std;

const int N = 1e5+10;

int n,m;
// size��ʾÿ�����ϵ��������ֻ�и��ڵ��size��������
int fa[N],size[N];

// ��ʼ��n��Ԫ��
void init(int n)
{
    // ��ʼ��ʱÿ���ڵ�ָ��������ÿ�����ϵĴ�СΪ1
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        size[i]=1;
    }
}

// ��ѯ���ĸ����ڲ�ѯx�Ĺ�����˳������·��ѹ��
int find(int x)
{
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);// ·��ѹ��
}

// �ϲ�x��y�����ļ���
void merge(int x,int y)
{
    x=find(x),y=find(y);
    // x��y��ͬһ���ϣ�Ҳ��Ҫ�ϲ����޷Ƕ༸������ı���
    if(x==y)return;
    // ���Ⱥϲ���С������Ⱥϲ�
    if(size[x]<size[y])
    {
        // x���Ϻϲ���y�����У�y���ϵĵ�������
        fa[x]=y;
        size[y]+=size[x];
    }
    else
    {
        // y���Ϻϲ���x�����У�x���ϵĵ�������
        fa[y]=x;
        size[x]+=size[y];
    }  
}

int main()
{
    scanf("%d%d",&n,&m);

    // ��ʼ������
    init(n);

    char op[5];
    int a,b;
    while(m--)
    {
        scanf("%s",op);
        if(op[0]=='C')
        {
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        else if(op[1]='1')
        {
            scanf("%d%d",&a,&b);
            // Puts��printf�������ԣ�ֻ���Զ���ӻ��з�����
            if(find(a)==find(b))puts("Yes");
            else puts("No");
        }
        else
        {
            scanf("%d",&a);
            // a���ڼ����еĵ�ĸ���
            printf("%d",size[find(a)]);
        }
    }
    return 0;
}