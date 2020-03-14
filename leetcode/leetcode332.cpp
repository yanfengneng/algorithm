#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        
    }
};

int main()
{
    vector<int> coins={1,2,5};
    cout<<Solution().coinChange(coins,11)<<endl;
}