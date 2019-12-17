#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    //��⣺̰���㷨����������ÿһλ����ǰλ����һλ���򽫸�λ���ּ�С1��Ȼ��֮�������ȫ����Ϊ9
    int monotoneIncreasingDigits(int N) {
        if(N<10)return N;
        deque<int> num;//��Nת��Ϊ���飬����ת��Ϊ�ַ���
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