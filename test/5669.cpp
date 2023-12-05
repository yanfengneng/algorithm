#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 贪心：每次匹配 groups 中单个数组在 nums 中的最前位置
    // 时间复杂度最大为O(n^2)，空间复杂度O(1)
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            // 检查 nums 从位置 j 顺序匹配 group[i] 是否匹配成功
            // 若成功，则 j 移动 group[i].size 的长度；若不成功，则j右移一位，我们从j下一个位置开始枚举
            if(check(groups[i],nums,j)){
                j+=groups[i].size(),i++;
                // group的n个数组已经匹配完了，则直接返回true
                if(i==groups.size())return true;
            }
            else j++;
        }
        // nums都遍历完了，group都没匹配完，返回false
        return false;
    }

    // 检查在 num 中从位置 j 开始匹配 g.size 是否成功
    bool check(vector<int>& group,vector<int>& nums,int j)
    {
        int k=0;
        while(k<group.size()&&j<nums.size()){
            if(group[k]==nums[j])k++,j++;
            else return false;
        }
        if(k==group.size())return true;
        else return false;
    }
};

int main()
{
    vector<vector<int>> groups={{1,-1,-1},{3,-2,0}};
    vector<int> nums={1,-1,0,1,-1,-1,3,-2,0};
    try{
        cout<<Solution().canChoose(groups,nums)<<endl;
    }
    catch(const exception& e){
        cout<<e.what()<<endl;
    }
    return 0;
}