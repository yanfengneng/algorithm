#include <iostream>
using namespace std;

const int N = 1e5+10;
char str[N];

// son[i][26]表示节点i最多有26个子节点；cnt[i]表示以节点i结尾的单词的个数；
// idx=0表示当前trie中只有根节点，idx=1表示当前trie中1个孩子节点。也就是说idx=i表示当前用到的孩子节点i，下次创建新的孩子节点时用孩子节点i+1。
// 下标为0的点既是根节点，又是空节点（一个节点没有子节点也会让它指向0）
int son[N][26],cnt[N],idx=0;

// 字符串插入
void insert(char str[])
{
    // p 表示根节点
    int p=0;
    // c语言中字符串结尾为'\0'
    for(int i=0;str[i];++i)
    {
        // 当前的子节点编号
        int u=str[i]-'a';
        // 如果节点p的孩子节点u为空，则创建这个节点
        if(!son[p][u])son[p][u]=++idx;
        // p 走到下一个节点
        p=son[p][u];
    }
    // 节点p结尾的单词数+1 
    cnt[p]++;
}

// 查询操作
int query(char str[])
{
    int p=0;
    for(int i=0;str[i];++i)
    {
        int u=str[i]-'a';
        // 查到空了，直接返回0
        if(!son[p][u])return 0;
        // 继续查找下一个子节点
        p=son[p][u];
    }
    // 返回以p结尾的单词个数
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