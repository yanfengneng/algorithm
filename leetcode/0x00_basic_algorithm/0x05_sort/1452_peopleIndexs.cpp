#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 题解的数据范围很小，100*100*500=5e6，不会超时
    // 题解：暴力法，时间复杂度O(N^2 * m)，空间复杂度O(1)
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        vector<int> res;
        // 给每个用户收藏清单里的公式按字母排序
        for(auto &item:f)sort(item.begin(),item.end());
        int n=f.size();

        // 进行暴力枚举
        for(int i=0;i<n;++i)
        {
            bool isSubset=false;
            for(int j=0;j<n;++j)
            {
                // 第i名用户是第j名用户的子集，则直接break
                // includes是判断子集的一个库函数，在C++17中引出的
                if(i!=j&&includes(f[j].begin(),f[j].end(),f[i].begin(),f[i].end()))
                {
                    isSubset=true;
                    break;
                }
            }
            // 第i名用户不是任何的子集，就添加i
            if(!isSubset)res.push_back(i);
        }

        return res;
    }
};

int main()
{
    vector<vector<string>> f({{"leetcode","google","facebook"},
    {"google","microsoft"},{"google","facebook"},{"google"},{"amazon"}});
    auto res=Solution().peopleIndexes(f);
    for(auto r:res)cout<<r<<" ";
    cout<<endl;
    return 0;
}