#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> result;
        int lastNum=K,i=A.size()-1;
        while(i>=0||lastNum>0)
        {
            if(i>=0)lastNum+=A[i--];
            result.push_back(lastNum%10);
            lastNum/=10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{
    vector<int> A{1,2,0,0};
    vector<int> num=Solution().addToArrayForm(A,34);
}