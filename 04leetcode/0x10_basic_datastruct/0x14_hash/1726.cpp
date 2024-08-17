#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // 先查询在统计
        unordered_map<int,int> mp;
        int res=0,n=nums.size();
        for(int i=0;i<n-3;++i)
        {
            for(int j=n-1;j>i+2;--j)
            {
                int l=i+1,r=j-1;
                int x=nums[i]*nums[j];
                while(l<r)
                {
                    int y=nums[l]*nums[r];
                    if(y>x)r--;
                    else if(y<x)l++;
                    else res+=8,l++,r--;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums={2,3,4,6};
    cout<<Solution().tupleSameProduct(nums)<<endl;
    return 0;
}