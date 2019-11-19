#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

class Trie{
private:
    int count;
    Trie* next[26];
public:
    Trie(){
        count=0;
        memset(next,0,sizeof(next));
    }
    void insert(string& word){
        Trie *root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->count++;
    }
    
    int search(string& word){
        Trie* root=this;
        for(const auto &w:word){
            if(root->next[w-'a']==nullptr)return 0;
            root=root->next[w-'a'];
        }
        return root->count;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.empty()||k==0)return {};
        map<string,int> record_1;
        vector<string> result;
        for(const auto& word:words){
            record_1[word]++;
        }
        vector<pair<string,int>> record_2(record_1.begin(),record_1.end());
        sort(record_2.begin(),record_2.end(),
             [](const pair<string,int>& a,const pair<string,int>& b)
             {
                 if(a.second==b.second)return a.first<b.first;
                 else return a.second>b.second;
              }
            );
        for(const auto& r:record_2)
        {
           if(k--==0)break;
            result.push_back(r.first);
        }
        return result;
    }
};

int main()
{
    vector<string> words={"i", "love", "leetcode", "i", "love", "coding"};
    map<string,int> record_1;
    for(const auto& word:words){
            record_1[word]++;
    }
   
    system("pause");
}