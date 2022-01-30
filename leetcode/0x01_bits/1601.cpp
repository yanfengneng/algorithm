#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 思路：无脑枚举，枚举所有请求是否被同意的所有情况
    int maximumRequests(int n, vector<vector<int>> g) {
        int m=g.size(),res=0;
        vector<int> cnt(n,0);
        for(int state=0;state<1<<m;++state){
            fill(cnt.begin(),cnt.end(),0);
            int step=0;
            for(int i=0;i<m;++i){
                if(state>>i&1)step++,cnt[g[i][0]]--,cnt[g[i][1]]++;
            }
            if(count(cnt.begin(),cnt.end(),0)==n)res=max(res,step);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> nums={{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
    cout<<Solution().maximumRequests(5,nums)<<endl;
    return 0;
}