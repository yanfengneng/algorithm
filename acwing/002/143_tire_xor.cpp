#include <iostream>
using namespace std;

// 由于每个数有31位（不含符号位），所以最多有31*N个节点
const int N = 1e5+10,M = 31*N;

int a[N];

// idi=i表示当前用的节点i，下次添加新节点时使用节点i+1
int son[M][2],idx=0;

void insert(int x)
{
    // 从根节点出发
    int p=0;
    // 高位存储在trie的最前面，也就是从左到右存储
    for(int i=30;i>=0;i--)
    {
        // 取第i位的数字
        int u=x>>i&1;
        // 如果p节点的孩子节点u为空，则创建一个新的节点，新的节点的编号为idx+1
        if(!son[p][u])son[p][u]=++idx;  
        // 移动到下一个孩子节点
        p=son[p][u];
    }
}

int query(int x)
{
    // res表示最大异或值，每次res*2表示左移一位，31循环后左移了31位了，+u表示加上当前的最低位数字
    int p=0,res=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        // 若p的孩子节点u的另一个相反方向存在，我们就走到相反方向去
        if(son[p][!u])
        {
            p=son[p][!u];
            res=res*2+!u;
        }
        // 相反方向的节点为空，只能顺着相同方向走了
        else
        {
            p=son[p][u];
            // res先左移一位，在加上最低位
            res=res*2+u;
        }
    }
    // 由于上面我们得到的异或另一个数组元素，此时我们需要将这个数组元素与x想异或得到 最到异或值
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
        // 先插入在查询，避免当tire为空时，查询空集
        insert(a[i]);
        res=max(res,query(a[i]));
    }
    printf("%d\n",res);
    return 0;
}