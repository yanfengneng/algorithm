#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //双指针法：指针i指向每串字符的同一个位置的字符，指针j用来遍历每个字符串
        if(strs.empty())return "";
        else if(strs.size()==1)return strs[0];
        string result="";
        //取第一个字符串为最长公共前缀，然后遍历每个字符串，来确定实际的最长公共前缀
        for(int i=0;i<strs[0].size();++i)//i表示指向每个字符串的同一个位置的字符
        {
            cout<<i<<endl;
            for(int j=1;j<strs.size();++j)//j遍历到每个字符串
                if(strs[0][i]!=strs[j][i]){
                    cout<<strs[j][i]<<endl;
                    return result;
                }
            result+=strs[0][i];
        }
        return result;
    }
};

int main()
{
    vector<string> strs={"flower","flow","flowig"};
    cout<<Solution().longestCommonPrefix(strs)<<endl;
}