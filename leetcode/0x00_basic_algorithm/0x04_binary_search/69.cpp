#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ֱ�Ӷ��ֲ���Ѱ��ƽ������������������ȡ����
    int mySqrt(int x) {
        if(x<=1)return x;
        int l=1,r=x/2;
        while(l<r)
        {
            // ��λ����������ȵȼ�С��+��-��*��/������Ҫ������������
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