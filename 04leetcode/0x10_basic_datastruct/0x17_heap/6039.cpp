#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
using LL = long long;
class Solution {
public:
    // 给x加1，其实就是给整体扩大了(x+1)/x=1+1/x倍，因此x越大收益越小，所以每次选择x最小的，然后让其+1
    int maximumProduct(vector<int>& a, int k) {
        // 使用小根堆，k次每次取最小值进行+1
        priority_queue<int,vector<int>,greater<int>> pq(a.begin(),a.end());
        while(k){
            // 每次取最小值和次最小值，然后让最小值直接加到次最小值最近的位置
            int x=pq.top();pq.pop();
            int y=pq.top(),cnt=y-x; // cnt为x加到y需要增长的次数
            if(cnt==0)x++,k--;      // 最小值和次最小值相等，则需把最小值+1即可，同时k减1
            else if(cnt<k)x+=cnt,k-=cnt; // x增加到y的次数小于k，则直接将x增加到y，同时将k减cnt
            else x+=k,k=0; // x增加到y的次数大于等于k，那么x最多增加k次了，同时k减为0
            pq.push(x);
        }
        LL res=1;
        while(pq.size()){
            res=res*pq.top()%mod;
            pq.pop();
        }
        return res;
    }
};

int main()
{
    vector<int> v={0,4};
    cout<<Solution().maximumProduct(v,5)<<endl;
    return 0;
}