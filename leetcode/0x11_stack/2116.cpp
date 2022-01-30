#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
// ������仯
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

    // idx��ʾ��������ʾ������s���ĸ��±ꣻcount��ʾ�������ŵ�����������������+1������������-1
    bool dfs(string s,int idx,int count){
        // ��֦��ö����������У�count<0��ʾ�������������������࣬�ض���Ч��������������s��һ�뻹�����ض���Ч
        if(count<0||count>s.size()/2)return false;
        // ����ݹ����
        if(idx>=s.size()){
            // count=0��ʾ����ƥ��ɹ��ˣ�count��0��ʾƥ�䲻�ɹ�
            if(count==0)return true;
            return false;
        }
        // ������ڣ�ֱ�ӷ��أ������ظ����㣻memo[idx][count]=1��ʾ��Чƥ�䣻-1��ʾ��Чƥ��
        if(memo[idx][count])return memo[idx][count]==1;
        // ����dfs
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