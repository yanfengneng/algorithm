#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> get_divisors(int x)
{
    vector<int> res;

    // ��x��Լ����СԼ��Ϊi����Լ��Ϊx/i��ֻҪ�����������������
    // i<=x/i  =>  i*i<=x������ֻҪö�ٵ�1~sqrt(x)������
    for(int i=1;i<=x/i;++i)
    {
        // x�ܱ�i��������һ������Ӹ���x���ߵ�����Լ��
        // ע���и����У���ֹ����Լ����ȣ���ȵĻ���ֻ���һ��
        if(x%i==0)
        {
            res.push_back(i);
            // ����һ�£���ֹ����Լ�����
            if(i!=x/i)res.push_back(x/i);
        }
    }
    // ��ĿҪ��������Լ����С��������
    sort(res.begin(),res.end());
    return res;
}

int main()
{

    cout<<sin()<<endl;
    int n;
    scanf("%d",&n);

    while(n--)
    {
        int x;
        scanf("%d",&x);
        auto res=get_divisors(x);
        for(auto r:res)printf("%d ",r);
        puts("");
    }

    return 0;
}