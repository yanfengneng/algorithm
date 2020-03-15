#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount)return 0;
        int res=INT_MAX;
        sort(coins.rbegin(),coins.rend());//由大到小排序，便于贪心地选取面值大的零钱
        dfs(coins,amount,0,0,res);
        return res==INT_MAX?-1:res;
    }

    //回溯寻找满足情况的最少零钱数，k表示一次可拿coins[i]的最大次数，若后面不能达到零钱完全兑换或者兑换的零钱数大于res时，用来回溯k--或剪枝
    //index用来遍历coins，count用来统计已用的零钱数
    void dfs(vector<int>& coins,int amount,int count,int index,int& res){
        if(amount==0){res=min(res,count);return;}
        if(index==coins.size())return;
        for(int k=amount/coins[index];k>=0&&k+count<res;--k){//k用来枚举所有零钱兑换的状态的
            dfs(coins,amount-k*coins[index],count+k,index+1,res);
        }
    }
};

int main()
{
    vector<int> c1={1,2,5},c2={2};
    cout<<Solution().coinChange(c1,11)<<endl;
    cout<<Solution().coinChange(c2,3)<<endl;
    system("pause");
}