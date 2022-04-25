#include <bits/stdc++.h>
using namespace std;

using LL = long long;

/*
逆向思维：直接枚举所有有趣数，然后判断枚举到有趣数是否在[x,y]之间，是就进行计数即可；
这样的最大时间复杂度为17*10*9*17=2.6w，是可以通过的
*/
int main()
{
    LL x,y;cin>>x>>y;

    int res=0;

    for(int i=3;i<=17;++i)// 有趣数：最小有3位数字，最大总共17位数字
        for(int j=0;j<10;++j)// 有趣数只有2个不同的数字，枚举第一个不同的数字j
            for(int k=0;k<10;++k)// 枚举第二个不同的数字k
                if(j!=k)// 判断下，第一个数字和第二个数字不能相同
                {
                    // 枚举由不同数字j，k组成所有有趣数，也就是i位数字某一位改为k
                    for(int u=0;u<i;++u)
                    {
                        string s(i,'0'+j);
                        s[u]='0'+k;
                        // 不能含前导0
                        if(s[0]=='0')continue;
                        LL v=stoll(s);
                        // 枚举得到的有趣数在[x,y]之间，则进行计数
                        if(v>=x&&v<=y)res++;
                    }
                }
    
    cout<<res<<endl;
    return 0;
}