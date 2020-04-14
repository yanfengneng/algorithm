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
            if(it.second&1)res+=it.second-1;//���������ַ���-1
            else res+=it.second;//����ż���ַ���
        }
        return res<s.size()?res+1:res;//����һ�����ַ������м�
    }
};

int main()
{
    cout<<Solution().longestPalindrome("abccccdd")<<endl;
}