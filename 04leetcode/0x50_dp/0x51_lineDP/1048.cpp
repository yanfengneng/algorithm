#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 转换为 LIS 来做
    int longestStrChain(vector<string>& ws) {
         // 按长度进行由小到大的排序
        sort(ws.begin(),ws.end(),[](const auto& a,const auto& b){
            return a.size()<b.size();
        });
        int n=ws.size();
        // f[i]表示以ws[i]结尾词链的最长长度，初始值为1，表示每个单词自行构成一个长度为1的长链
        vector<int> f(n,1);
        int res=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<i;++j)
                if(check(ws[j],ws[i])){
                    f[i]=max(f[i],f[j]+1);
                    res=max(res,f[i]);
                }
        return res;
    }

    // 使用双指针判断a是否为b的子序列
    bool check(const string& a,const string &b){
        int m=a.size(),n=b.size();
        int i=0,j=0;
        while(i<m&&j<n){
            if(a[i]==b[j])i++;
            j++;
        }
        return i==m;
    }
};

int main()
{
    vector<string> ws={"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout<<Solution().longestStrChain(ws)<<endl;
    return 0;
}