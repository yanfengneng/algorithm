#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    //题解：贪心算法，遍历数字每一位，当前位比下一位大，则将该位数字减小1，然后之后的数字全部变为9
    int monotoneIncreasingDigits(int N) {
        if(N<10)return N;
        deque<int> num;//将N转换为数组，避免转换为字符串
        while(N)
        {
            num.push_front(N%10);
            N/=10;
        }
        int size=num.size();
        for(int i=1;i<size;++i)
        {
            if(num[i-1]>num[i])
            {
                num[i-1]--;
                for(int j=i;j<size;++j)num[j]=9;
                i=0;
            }
        }
        int result=0;
        for(int n:num)result=result*10+n;
        return result;
    }
};

int main()
{
    cout<<Solution().monotoneIncreasingDigits(332)<<endl;
    system("pause");
}