#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
// 加入记忆化
int memo[N][N];
class Solution {
public:
    bool canBeValid(string s, string locked) {
        for(int i=0;i<s.size();++i){
            if(locked[i]=='0')s[i]='*';
        }
        return checkValidString(s);
    }

    bool checkValidString(string s) {
        memset(memo,0,sizeof memo);
        return dfs(s,0,0);
    }

    // idx表示索引，表示遍历到s中哪个下标；count表示左右括号的数量，遇到左括号+1，遇到右括号-1
    bool dfs(string s,int idx,int count){
        // 剪枝：枚举所有情况中，count<0表示右括号数比左括号数多，必定无效；或左括号数比s的一半还长，必定无效
        if(count<0||count>s.size()/2)return false;
        // 到达递归出口
        if(idx>=s.size()){
            // count=0表示最终匹配成功了；count非0表示匹配不成功
            if(count==0)return true;
            return false;
        }
        // 缓存存在，直接返回，避免重复计算；memo[idx][count]=1表示有效匹配；-1表示无效匹配
        if(memo[idx][count])return memo[idx][count]==1;
        // 继续dfs
        bool flag=false;
        if(s[idx]=='(')flag|=dfs(s,idx+1,count+1);
        else if(s[idx]==')')flag|=dfs(s,idx+1,count-1);
        else flag|=(dfs(s,idx+1,count+1)||dfs(s,idx+1,count-1)||dfs(s,idx+1,count));
        memo[idx][count]=flag?1:-1;
        return flag;
    }
};

int main()
{
    cout<<Solution().canBeValid("))()))","010100")<<endl;
    return 0;
}