#include <iostream>
#include <cstring>
using namespace std;

int n1,n2,m;

const int N = 510, M =1e5+10;

// 邻接表，存稀疏图
int h[N],e[M],ne[M],idx=0;
// match[y]=x表示y号妹子的男朋友为x号男生
int match[N];
// 临时预定数组，flag[y]=x表示妹子y被男生x预定了
bool flag[N];

void add(int a,int b)
{
    // 头插法
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x)// 判断x号男生是否能匹配到妹子
{
    // 遍历男生x喜欢的妹子
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        // 在这轮匹配中，妹子j还没有被预定
        if(!flag[j])
        {
            // 标记j号妹子被预定了
            flag[j]=true;
            // 若j号妹子单身或j号妹子的男朋友可以换另一个自己喜欢的妹子，则x号男生匹配成功
            if(!match[j]||find(match[j]))
            {
                match[j]=x;
                return true;
            }
        }
    }
    // 自己喜欢的妹子都有男朋友了，匹配失败
    return false;
}

int main()
{
    scanf("%d%d%d",&n1,&n2,&m);

    // 初始化邻接表顶点数组
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        // 只用左边的点指向右边即可
        add(a,b);
    }

    int res=0;
    for(int i=1;i<=n1;++i)
    {
        // 每轮找妹子都要给预定清空，这样方便给有备胎的男生找到下家，让i号男生脱单
        memset(flag,0,sizeof flag);
        // i号男生是否匹配到妹子
        if(find(i))res++;
    }

    printf("%d\n",res);

    return 0;
}