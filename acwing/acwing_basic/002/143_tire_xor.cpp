#include <iostream>
using namespace std;

// ����ÿ������31λ����������λ�������������31*N���ڵ�
const int N = 1e5+10,M = 31*N;

int a[N];

// idi=i��ʾ��ǰ�õĽڵ�i���´�����½ڵ�ʱʹ�ýڵ�i+1
int son[M][2],idx=0;

void insert(int x)
{
    // �Ӹ��ڵ����
    int p=0;
    // ��λ�洢��trie����ǰ�棬Ҳ���Ǵ����Ҵ洢
    for(int i=30;i>=0;i--)
    {
        // ȡ��iλ������
        int u=x>>i&1;
        // ���p�ڵ�ĺ��ӽڵ�uΪ�գ��򴴽�һ���µĽڵ㣬�µĽڵ�ı��Ϊidx+1
        if(!son[p][u])son[p][u]=++idx;  
        // �ƶ�����һ�����ӽڵ�
        p=son[p][u];
    }
}

int query(int x)
{
    // res��ʾ������ֵ��ÿ��res*2��ʾ����һλ��31ѭ����������31λ�ˣ�+u��ʾ���ϵ�ǰ�����λ����
    int p=0,res=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        // ��p�ĺ��ӽڵ�u����һ���෴������ڣ����Ǿ��ߵ��෴����ȥ
        if(son[p][!u])
        {
            p=son[p][!u];
            res=res*2+!u;
        }
        // �෴����Ľڵ�Ϊ�գ�ֻ��˳����ͬ��������
        else
        {
            p=son[p][u];
            // res������һλ���ڼ������λ
            res=res*2+u;
        }
    }
    // �����������ǵõ��������һ������Ԫ�أ���ʱ������Ҫ���������Ԫ����x�����õ� ����ֵ
    res^=x;
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);

    int res=0;

    for(int i=0;i<n;++i)
    {
        // �Ȳ����ڲ�ѯ�����⵱tireΪ��ʱ����ѯ�ռ�
        insert(a[i]);
        res=max(res,query(a[i]));
    }
    printf("%d\n",res);
    return 0;
}