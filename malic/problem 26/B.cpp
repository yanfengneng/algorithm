#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> father; // ����
    vector<int> len;    // ���Ĵ�С
    int cnt=0;          // ��ͨ���ĸ���
public:
    UnionFind(int n)    // ���캯����ʼ������
    {
        father.resize(n+1),len.resize(n+1);
        cnt=n;
        for(int i=1;i<=n;++i)
        {
            father[i]=i;    // ��ʼ��ʱ���ڵ�ָ����
            len[i]=1;       // ��ʼ��ʱÿ������СΪ1
        }
    }

    int find(int x)     // ��ѯ���ĸ�
    {
        // �ڲ�ѯ���и��ڵ�����У�˳�����·��ѹ��
        while(father[x]!=x)
        {
            father[x]=father[father[x]];
            x=father[x];
        }
        return x;
    }

    void merge(int x,int y) // �ϲ�x��y�����ļ���
    {
        x=find(x),y=find(y);
        if(x==y)return;     // x��yΪͬһ���ϲ���Ҫ�ϲ�
        // ���Ƚ��кϲ���С������Ⱥϲ�
        if(len[x]<len[y])
        {
            father[x]=y;
            len[y]+=len[x];
        } 
        else
        {
            father[y]=x;
            len[x]+=len[y];
        }
        cnt--;       
    }

    int count(){return cnt;}
};

int n,m;

int main()
{
    int cnt=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m)break;
        UnionFind uf(n);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            uf.merge(a,b);
        }
        cnt++;
        printf("Case %d: %d\n",cnt,uf.count());
    }
    return 0;
}