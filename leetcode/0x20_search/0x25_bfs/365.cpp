#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
class Solution {
public:
    // dfs��ö������״̬
    bool canMeasureWater(int A, int B, int t) {
        if(!t)return true;
        if(A+B<t)return false;
        // ���� visit ����ֹ�����ظ�״̬
        set<PII> v;
        function<bool(PII)> dfs=[&](PII a)->bool{
            if(v.count(a))return false;
            int x=a.first,y=a.second;
            if(x==t||y==t||x+y==t)return true;
            // ��Ǹõ��ѱ�����
            v.insert(a);
            bool f=false;
            // ö�����е�״̬���� dfs
            // 1��װ�� A ��װ�� B
            f|=dfs({A,y}),f|=dfs({x,B});
            // 2����� A ����� B
            f|=dfs({0,y}),f|=dfs({x,0});
            // 3���໥��ˮ
            int need=min(x,B-y);// A �� B ��ˮ
            f|=dfs({x-need,y+need});
            need=min(A-x,y);// B �� A ��ˮ
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