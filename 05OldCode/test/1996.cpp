#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int n=nums.size(),res=0;
        for(int a=0;a<n;++a)
            for(int b=a+1;b<n;++b)
                for(int c=b+1;c<n;++c)
                    for(int d=c+1;d<n;++d)
                        if(nums[a]+nums[b]+nums[c]==nums[d])
                            res++;
        return res;
    }
};

int main()
{
    vector<int> nums={28,8,49,85,37,90,20,8};
    Solution().countQuadruplets(nums);
    return 0;
}