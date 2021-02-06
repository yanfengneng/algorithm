#include <bits/stdc++.h>
using namespace std;

// x若为2的幂，则直接返回x-1，
int dfs(int x)
{
    if(x==0||x==1)return 0;
    int two=1;
    // 获得 <=x 的2的最大幂
    while(two*2<=x)two*=2;
    // two 为 2 的幂，返回two-1即可，剩下的继续递归即可
    return two-1+dfs(x-two);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int x;
        cin>>x;
        cout<<dfs(x)<<endl;
    }
    return 0;
}