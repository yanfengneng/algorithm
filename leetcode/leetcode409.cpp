#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> count;
        for(char ch:s)count[ch]++;
        int res=0;
        for(auto it:count){
            if(it.second&1)res+=it.second-1;//加上奇数字符数-1
            else res+=it.second;//加上偶数字符数
        }
        return res<s.size()?res+1:res;//加上一个单字符放在中间
    }
};

int main()
{
    cout<<Solution().longestPalindrome("abccccdd")<<endl;
}