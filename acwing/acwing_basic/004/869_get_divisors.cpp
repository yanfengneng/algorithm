#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> get_divisors(int x)
{
    vector<int> res;

    // 求x的约数，小约数为i，大约数为x/i，只要满足这个条件就行了
    // i<=x/i  =>  i*i<=x，所以只要枚举到1~sqrt(x)就行了
    for(int i=1;i<=x/i;++i)
    {
        // x能被i整除，则一次性添加根号x两边的左右约数
        // 注意有个特判，防止两个约数相等，相等的话，只添加一个
        if(x%i==0)
        {
            res.push_back(i);
            // 特判一下，防止两个约数相等
            if(i!=x/i)res.push_back(x/i);
        }
    }
    // 题目要求是所有约数由小到大排序
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