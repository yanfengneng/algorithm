#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 直接二分查找寻找平方根，整数根是向下取整的
    int mySqrt(int x) {
        if(x<=1)return x;
        int l=1,r=x/2;
        while(l<r)
        {
            // 移位运算符的优先等级小于+，-，*，/；所以要用括号括起来
            int mid=l+((r-l+1)>>1);
            if(mid<=x/mid)l=mid;
            else r=mid-1;
        }
        return l;
    }
};

int main()
{
    cout<<Solution().mySqrt(4)<<endl;
    return 0;
}