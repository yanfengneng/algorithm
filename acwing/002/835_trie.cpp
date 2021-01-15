#include <iostream>
using namespace std;

const int N = 1e5+10;
char str[N];

// son[i][26]��ʾ�ڵ�i�����26���ӽڵ㣻cnt[i]��ʾ�Խڵ�i��β�ĵ��ʵĸ�����
// idx=0��ʾ��ǰtrie��ֻ�и��ڵ㣬idx=1��ʾ��ǰtrie��1�����ӽڵ㡣Ҳ����˵idx=i��ʾ��ǰ�õ��ĺ��ӽڵ�i���´δ����µĺ��ӽڵ�ʱ�ú��ӽڵ�i+1��
// �±�Ϊ0�ĵ���Ǹ��ڵ㣬���ǿսڵ㣨һ���ڵ�û���ӽڵ�Ҳ������ָ��0��
int son[N][26],cnt[N],idx=0;

// �ַ�������
void insert(char str[])
{
    // p ��ʾ���ڵ�
    int p=0;
    // c�������ַ�����βΪ'\0'
    for(int i=0;str[i];++i)
    {
        // ��ǰ���ӽڵ���
        int u=str[i]-'a';
        // ����ڵ�p�ĺ��ӽڵ�uΪ�գ��򴴽�����ڵ�
        if(!son[p][u])son[p][u]=++idx;
        // p �ߵ���һ���ڵ�
        p=son[p][u];
    }
    // �ڵ�p��β�ĵ�����+1 
    cnt[p]++;
}

// ��ѯ����
int query(char str[])
{
    int p=0;
    for(int i=0;str[i];++i)
    {
        int u=str[i]-'a';
        // �鵽���ˣ�ֱ�ӷ���0
        if(!son[p][u])return 0;
        // ����������һ���ӽڵ�
        p=son[p][u];
    }
    // ������p��β�ĵ��ʸ���
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I')insert(str);
        else printf("%d\n",query(str));
    }
    return 0;
}