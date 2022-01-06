#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 思路：前缀和，优雅解决，时间复杂度O(n)，空间复杂度O(n)
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        // pre[i]表示数列前i项的元素和，即nums[0...i-1]的元素和
        for(int i=1;i<=n;++i){
            pre[i]=pre[i-1]+nums[i-1];
        }
        // 区间[j,i](下标从1开始计数)的元素和为pre[i]-pre[j-1]
        for(int i=0;i<n;++i){
            if(i==0&&pre[n]-pre[1]==0)return 0;
            else if(i==n-1&&pre[n-1]==0)return n-1;
            else if(pre[i-1]-pre[0]==pre[n]-pre[i])return i;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums={1, 7, 3, 6, 5, 6};
    cout<<Solution().pivotIndex(nums)<<endl;
    return 0;
}