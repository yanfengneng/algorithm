#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();++i)
        {
            while(nums[i]>0&&nums[i]&&nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<nums.size();++i)
            if(nums[i]!=i+1)
                return i+1;
        return nums.size()+1;
    }
};

int main()
{
    vector<int> nums{3,4,-1,1};
    Solution().firstMissingPositive(nums);
}