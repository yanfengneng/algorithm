#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //C++ split
        istringstream strs(str);
        vector<string> words;
        string word;
        while(strs>>word){
            words.push_back(word);
        }
        if(pattern.size()!=words.size())return false;
        map<char,string> record;//建立映射关系 <字符，单词>
        for(int i=0;i<pattern.size();++i){
            if(record.count(pattern[i])){//若该字符在map中，则判断该字符对应的单词是否与words[i]相等即可
                if(record[pattern[i]]!=words[i])return false;
            }
            else{//若该字符不在map中，则添加<字符，单词>
                auto flag=record.insert({pattern[i],words[i]});
                if(!flag.second){
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    cout<<Solution().wordPattern("abba","dog dog dog dog")<<endl;
}