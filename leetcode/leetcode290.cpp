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
        map<char,string> record;//����ӳ���ϵ <�ַ�������>
        for(int i=0;i<pattern.size();++i){
            if(record.count(pattern[i])){//�����ַ���map�У����жϸ��ַ���Ӧ�ĵ����Ƿ���words[i]��ȼ���
                if(record[pattern[i]]!=words[i])return false;
            }
            else{//�����ַ�����map�У������<�ַ�������>
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