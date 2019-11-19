#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    //解法1：动态规划
    string longestPalindrome_1(string s) {
        if(s.size()<2)return s;
        
        //dp[i][j]表示s[i]至s[j]是否为回文串，是为1，不是为0
        int size=s.size(),dp[size][size];
        memset(dp,0,sizeof(dp));
        
        int max=1,start=0;
        
        //初始化边界值
        for(int i=0;i<size;++i){
            dp[i][i]=1;
            if(i<size-1&&s[i]==s[i+1]){
                dp[i][i+1]=1;//是回文串，表示为1
                max=2;
                start=i;
            }
        }
        
        for(int l=3;l<=size;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<size;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);
    }
    
    //解法2：马拉车算法
    string longestPalindrome_2(string s)
    {
        string t="$#";
        for(auto c:s){
            t+=c;
            t+='#';
        }
        
        vector<int> p(t.size(),0);
        
        //mx表示某个回文串延伸在最右端半径的下标，id表示这个回文子串最中间位置下标
        //resLen表示对应在s中的最大子回文串的半径，resCenter表示最大子回文串的中间位置
        int mx=0,id=0,resLen=0,resCenter=0;
        
        for(int i=1;i<t.size();++i)
        {
            p[i]=mx>i?min(p[2*id-i],mx-i):1;
            
            //遇到三种特殊的情况，需要利用中心扩展法
            while(t[i+p[i]]==t[i-p[i]])p[i]++;
            
            //半径下标i+p[i]超过边界mx，需要更新
            if(mx<i+p[i]){
                mx=i+p[i];
                id=i;
            }
            
            //更新最大回文子串的信息，半径及中间位置
            if(resLen<p[i]){
                resLen=p[i];
                resCenter=i;
            }
        }
        
        //最长回文子串长度为半径-1，起始位置为中间位置减去半径再除以2
        return s.substr((resCenter-resLen)/2,resLen-1);
    }
    
    //解法3：中心扩展法
    string longestPalindrome(string s){
        if(s.size()<2)return s;
        
        //回文串的起始和终止位置以及最大回文串的长度
        int start=0,end=0,mLen=0;
        
        for(int i=0;i<s.size();++i)
        {
            int len1=expand(s,i,i);//以i为中心向两边扩展
            int len2=expand(s,i,i+1);//以两个元素为中心向两边扩展
            
            mLen=max(max(len1,len2),mLen);//更新最大回文串长度
            
            if(mLen>end-start+1){//更新回文串的起始和终止位置
                start=i-(mLen-1)/2;
                end=i+mLen/2;
            }
        }
        return s.substr(start,mLen);
    }
    
private:
    int expand(string s,int left,int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;//0 变为 -1
            right++;//0 变为 1
        }
        return right-left-1;//1+1-1=1
    }
};

int main()
{
    cout<<Solution().longestPalindrome("babad")<<endl;
    cout<<Solution().longestPalindrome("12211")<<endl;
    system("pause");
}