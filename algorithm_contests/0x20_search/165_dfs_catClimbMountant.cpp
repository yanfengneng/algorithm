#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,w;
// cab[i] 用来存放第i辆小车装的猫猫重量
int c[25],cab[25];
int res=0;

// idx 表示 处理第 idx 只猫猫乘作那辆小车，cnt 表示我们已经租了 cnt 辆小车了
void dfs(int idx,int cnt)
{
    // 剪枝：若当前租的小车数大于目前的最小值了，我们继续搜索下去也不能找到最优结果，进行剪枝
    if(cnt>=res)return;
    // 找到一个可行解
    if(idx==n)
    {
        res=min(res,cnt);
        return;
    }
    /*枚举选择列表，在[1,cnt]辆车中选一辆进行装猫猫*/
    for(int i=1;i<=cnt;++i)
    {
        // 第i辆小车上还能装第idx只猫猫，则装取猫猫
        if(cab[i]+c[idx]<=w)
        {
            /*choose过程：加入决策*/
            cab[i]+=c[idx];
            /*进入下一次决策*/
            dfs(idx+1,cnt);
            /*unchooose过程：移除该决策*/
            cab[i]-=c[idx];
        }
    }

    /*尝试用一辆新的小车来装猫猫*/
    /*加入此次决策*/
    cab[cnt+1]=c[idx];
    /*进入下一次决策*/
    dfs(idx+1,cnt+1);
    /*移除此次决策*/
    cab[cnt+1]=0;
}

int main()
{
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;++i)scanf("%d",&c[i]);
    // 由大到小排序，贪心先搜索重量较重的，减少搜索树“分支”的数量
    sort(c,c+n);        // 先由小到大排序
    reverse(c,c+n);     // 再反转一下，变成由大到小排序

    // 最坏情况，每个猫猫一辆小车
    res=n;
    dfs(0,1);
    printf("%d",res);
    return 0;
}