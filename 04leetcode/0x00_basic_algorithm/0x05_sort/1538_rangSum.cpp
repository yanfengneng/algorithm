#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

class Solution {
public:
    // ��⣺ǰ׺��
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> record;

        // ��������������ĺͣ�����nums��СΪ10^3,ʹ��O(n^2)���ᳬʱ
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

        // ��������������
        sort(record.begin(),record.end());

        // ����ǰ׺��
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