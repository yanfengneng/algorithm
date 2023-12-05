#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
// 状态f[i]表示所有a[i]结尾的上升子序列的长度最大值
int n,a[N],f[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];

    // 枚举所有以a[i]结尾的子序列
    for(int i=1;i<=n;++i)
    {
        // 只有a[i]一个数
        f[i]=1;
        // 进行状态计算；由于j是小于i的，所以之前由小到大枚举i时，比i小的j已经被计算过了
        // 此时用的就是计算过的上升子序列的最大值f[j]，进而进行状态转移
        for(int j=1;j<i;++j)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+1);
    }

    int res=0;
    // 求解完所有的以a[i]结尾的最大上升子序列得到f[i]后，从中取一个max，得到最终答案
    for(int i=1;i<=n;++i)res=max(f[i],res);
    cout<<res<<endl;
    return 0;
}