#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int size=pow(2,n);
        vector<int> res;
        res.push_back(start);
        helper(res,0,size);
        return res;
    }
    void helper(vector<int>& res,int i,int size){
        if(i==size)return;
        if(i!=res[0]){
            if(abs(res.back()-i)%2==0||abs(res.back()-i)==1){
                res.push_back(i);
                helper(res,i+1,size);
            }
            else return;
        }
    }
};

int main()
{
    vector<int> res=Solution().circularPermutation(2,3);
    for(auto it:res)
        cout<<it<<" ";
    cout<<endl;
    
}