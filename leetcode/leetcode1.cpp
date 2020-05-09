#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> record;
        for(int i=0;i<nums.size();++i){
            record.insert({nums[i],i});
        }
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            if(record.count(target-nums[i])&&(record[target-nums[i]]!=i)){
                res.push_back(i);
                res.push_back(record[target-nums[i]]);
                return res;
            }
        }
        return {};
    }
};

int main()
{
    vector<int> nums={3,3};
    vector<int> res=Solution().twoSum(nums,6);
    for(int r:res){
        cout<<r<<" ";
    }
    cout<<endl;
}