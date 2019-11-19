#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for(auto num:nums)
        {
           int size=result.size();
           for(int i=0;i<size;++i)
           {
               vector<int> temp=result[i];
               temp.push_back(num);
               result.push_back(temp);
           }
        }
        return result;
    }   
};

int main()
{
    vector<int> nums={1,2,3};
    vector<vector<int>> result=Solution().subsets(nums);

}