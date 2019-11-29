#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    //题解1：作弊法
    int divide_1(int dividend, int divisor) {
       if (dividend==-2147483648&&divisor==-1)return INT_MAX;
       return dividend/divisor;
    }

    //题解2：除法，计算被除数有几个除数就是最终结果
    int divide(int dividend, int divisor){
        int sign=1;
        if ((dividend>0&&divisor>0)||(dividend<0&&divisor < 0)){
            sign=0;
        }
        long long dd=abs((long long)dividend),ds=abs((long long)divisor),result=0;
        while(dd>=ds)
        {
            long long temp=ds,i=1;
            while(dd>=temp)
            {
                dd-=temp;
                result+=i;
                temp<<=1;
                i<<=1;
            }
        }
        result=sign==0?result:-result;
        if(result<INT_MIN)return INT_MIN;
        if(result>INT_MAX)return INT_MAX;
        return result;
    }
};

int main()
{
    int result=Solution().divide(123456,9);
    cout<<result<<endl;
}