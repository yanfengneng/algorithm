#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution_1 {
private:
    vector<vector<string>> result;
    vector<string> temp;
    int dp[1001][1001]={0};
public:
    //题解1：dp+dfs
    vector<vector<string>> partition(string& s) {
        if(s.empty())return {};
        
        int n=s.size();
        
        //建立dp数组，也就是求回文串
        for(int i=0;i<n;++i){
            for(int j=0;j<=i;++j){
                if(s[i]==s[j]&&(i-j<2||dp[j+1][i-1]))
                    dp[j][i]=1;
            }
        }
        
        dfs(0,n,s);
        
        return result;
    }
    
    void dfs(int i,int n,string& s){
        if(i==n){result.push_back(temp);return;}
        for(int j=i;j<n;++j)
        {
            if (dp[i][j]) {
				temp.push_back(s.substr(i, j-i+1));
				dfs(j + 1, n, s);
				temp.erase(temp.end() - 1);
			}
        }
    }
    
};


class Solution{
public:
    //题解2：回溯法
    vector<vector<string>> partition(const string& s) {
        if(s.empty())return {};
        vector<vector<string>> result;
        vector<string> track;
        backtrack(s,track,result);
        return result;
    }
    
    void backtrack(string s,vector<string>& track,vector<vector<string>>& result)
    {
        if(s.empty())//选择列表已空，即已分割完回文串
            result.push_back(track);
        else{
            for(int i=1;i<=s.size();++i)
            {
                if(isVaild(s.substr(0,i)))
                {
                    /*choose过程*/
                    track.push_back(s.substr(0,i));//加入决策路径
                    /*进入下一步决策*/
                    backtrack(s.substr(i),track,result);//s变小了，移除这个选择了
                    /*unchoose过程*/
                    track.pop_back();//移除这个选择
                }
            }
        }
    }
    
    bool isVaild(string s)
    {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(s[left]!=s[right])return false;
            left++;right--;
        }
        return true;
    }
};

int main()
{
    vector<vector<string>> result=Solution().partition("abb");
    for(const auto& re:result)
    {
        for(auto r:re)
            cout<<r<<" ";
        cout<<endl;
    }    
}