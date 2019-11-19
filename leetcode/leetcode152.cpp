#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        //a��¼�� nums[i-1] ��β�ĳ˻���Сֵ��b��¼��nums[i-1] ��β�ĳ˻����ֵ
        int a=1,b=1;
        int Max=INT_MIN;
        for(int i=0;i<n;++i)
        {
            int aa=a*nums[i];
            int bb=b*nums[i];
            
            a=min(nums[i],min(aa,bb));
            b=max(nums[i],max(aa,bb));
            
            Max=max(Max,b);
        }
        return Max;
    }
};

int main()
{
    vector<int> v1{2,3,-2,4};
    vector<int> v2{-2,0,-1};
    cout<<Solution().maxProduct(v1)<<endl;
    cout<<Solution().maxProduct(v2)<<endl;
    return 0;
}