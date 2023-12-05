#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        // 用flag来记录是否前面出现b，则遍历到a时，若前面出现b则直接返回false
        bool flag=false;
        for(char ch:s){
            if(ch=='a')
                if(flag)return false;
            else flag=true;
        }
        return true;
    }
};

int main()
{
    cout<<Solution().checkString("aaabbb")<<endl;
    return 0;
}