#include <bits/stdc++.h>
using namespace std;


// 前缀和+hashmap经典套路：统计数组中有多少对相同的数字，使用先查询再插入的方法
int solve1(vector<int> pre)
{
    unordered_map<int,int> cnt; 
    int res=0;
    // 0 0 1 1 0 0 2 3 5
    for(int x:pre){
        // 比如说查询到第四个 0 时，之前的三个 0 都被计数了，此时第四个 0 与前面的三个 0 构成相同的数对，有三对。
        // 所以对于数组中统计相同数字的对数时，使用hashmap的经典套路：先查询后插入
        res+=cnt[x]++;
    }
    return res;
}

int main()
{
    vector<int> pre={0,0,1,1,0,0,2,3,5};
    cout<<solve1(pre)<<endl;
    return 0;
}