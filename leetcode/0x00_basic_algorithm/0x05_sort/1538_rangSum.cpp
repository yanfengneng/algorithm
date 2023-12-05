#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

class Solution {
public:
    // 题解：前缀和
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> record;

        // 计算连续子数组的和，由于nums大小为10^3,使用O(n^2)不会超时
        for(int i=0;i<n;++i)
        {
            int sum=nums[i];
            record.push_back(sum);
            for(int j=i+1;j<n;++j)
            {
                sum+=nums[j];
                record.push_back(sum);
            }
        }

        // 将数组升序排序
        sort(record.begin(),record.end());

        // 计算前缀和
        vector<int> prefixSum(record.size()+1,0);
        for(int i=1;i<prefixSum.size();++i)prefixSum[i]=prefixSum[i-1]%mod+record[i-1]%mod;

        return (prefixSum[right]-prefixSum[left-1])%mod;
    }
};

int main()
{
    vector<int> nums={1,2,3,4};
    cout<<Solution().rangeSum(nums,4,1,5);
    return 0;
}