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
    //���1��dp+dfs
    vector<vector<string>> partition(string& s) {
        if(s.empty())return {};
        
        int n=s.size();
        
        //����dp���飬Ҳ��������Ĵ�
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
    //���2�����ݷ�
    vector<vector<string>> partition(const string& s) {
        if(s.empty())return {};
        vector<vector<string>> result;
        vector<string> track;
        backtrack(s,track,result);
        return result;
    }
    
    void backtrack(string s,vector<string>& track,vector<vector<string>>& result)
    {
        if(s.empty())//ѡ���б��ѿգ����ѷָ�����Ĵ�
            result.push_back(track);
        else{
            for(int i=1;i<=s.size();++i)
            {
                if(isVaild(s.substr(0,i)))
                {
                    /*choose����*/
                    track.push_back(s.substr(0,i));//�������·��
                    /*������һ������*/
                    backtrack(s.substr(i),track,result);//s��С�ˣ��Ƴ����ѡ����
                    /*unchoose����*/
                    track.pop_back();//�Ƴ����ѡ��
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