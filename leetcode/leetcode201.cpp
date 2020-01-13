#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int sum=n;
        for(int i=m;i<n;++i){
            sum&=i;
        }
        return sum;
    }
};

int main()
{
    cout<<Solution().rangeBitwiseAnd(0,2147483647)<<endl;
}