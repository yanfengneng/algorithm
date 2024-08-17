#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ��⣺ǰ׺��
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(),m=l.size();
        vector<bool> res;

        // ǰ׺��Ԥ����
        vector<int> preSum(n+1,0);
        for(int i=1;i<=n;++i)preSum[i]=preSum[i-1]+nums[i-1];

        for(int i=0;i<m;++i)
        {
            // ��������[l,r]�ĺ�
            int sum=preSum[r[i]+1]-preSum[l[i]];
            // �Ȳ�������͹�ʽs=n*(a1+an)/2
            int a1=1e5+10,an=-1e5-10;
            for(int j=l[i];j<=r[i];++j)
            {
                if(a1>nums[j])a1=nums[j];
                if(an<nums[j])an=nums[j];
            }
            if(sum==(a1+an)*(r[i]-l[i]+1)/2)res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};

int main()
{
    vector<int> nums={-3,-6,-8,-4,-2,-8,-6,0,0,0,0},l={5,4,3,2,4,7,6,1,7},r={6,5,6,3,7,10,7,4,10};
    auto res=Solution().checkArithmeticSubarrays(nums,l,r);
    for(auto r:res)
        cout<<r<<" ";
    cout<<endl;
    return 0;
}