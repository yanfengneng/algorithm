#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        
        int left=0,right=0,n=nums.size();
        
        while(right<n)
        {
            if(right-left+1==k)
            {
                vector<int> temp(nums.begin()+left,nums.begin()+right+1);
                sort(temp.begin(),temp.end());
                int t=temp.size();
                if(t%2==0){
                    result.push_back(temp[t/2]/2.0+temp[t/2-1]/2.0);
                }
                else{
                    result.push_back(temp[t/2]);
                }
                left++;
            }
            right++;
        }
        return result;
    }
};
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), k /  2);
        for (int i = k; ; ++i) {
            res.push_back((*mid + *prev(mid,  1 - k % 2)) / 2);        
            if (i == nums.size()) return res;
            ms.insert(nums[i]);
            if (nums[i] < *mid) --mid;
            if (nums[i - k] <= *mid) ++mid;
            ms.erase(ms.lower_bound(nums[i - k]));
        }
        return res;
    }
int main()
{
    vector<int> nums{1,4,2,3};
    vector<double> v=Solution().medianSlidingWindow(nums,4);
    for(auto it:v)cout<<it<<" ";
    cout<<endl;
    system("pause");
}