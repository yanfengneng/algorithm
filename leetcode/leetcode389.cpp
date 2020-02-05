#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int count_s[26],count_t[26];
        memset(count_s,0,sizeof(count_s));
        memset(count_t,0,sizeof(count_t));
        for(char& c:s)count_s[c-'a']++;
        for(char& c:t)count_t[c-'a']++;
        for(int i=0;i<26;++i){
            if(count_s[i]!=count_t[i])
                return 'a'+i;
        }
        return 'a';
    }
};

int main()
{
    cout<<Solution().findTheDifference("abcd","abcde")<<endl;
}