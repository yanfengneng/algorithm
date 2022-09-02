#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
class Solution {
public:
    // dfs：枚举所有状态
    bool canMeasureWater(int A, int B, int t) {
        if(!t)return true;
        if(A+B<t)return false;
        // 定义 visit 来防止访问重复状态
        set<PII> v;
        function<bool(PII)> dfs=[&](PII a)->bool{
            if(v.count(a))return false;
            int x=a.first,y=a.second;
            if(x==t||y==t||x+y==t)return true;
            // 标记该点已被访问
            v.insert(a);
            bool f=false;
            // 枚举所有的状态进行 dfs
            // 1、装满 A 或装满 B
            f|=dfs({A,y}),f|=dfs({x,B});
            // 2、清空 A 或清空 B
            f|=dfs({0,y}),f|=dfs({x,0});
            // 3、相互倒水
            int need=min(x,B-y);// A 向 B 倒水
            f|=dfs({x-need,y+need});
            need=min(A-x,y);// B 向 A 倒水
            f|=dfs({x+need,y-need});
            return f;
        };
        return dfs({0,0});
    }
};

int main()
{
    cout<<Solution().canMeasureWater(104579,104593,12444)<<endl;
    return 0;
}