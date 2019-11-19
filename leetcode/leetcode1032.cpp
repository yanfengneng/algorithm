#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Trie{
private:
    bool is_string=false;
    Trie* next[26]={nullptr};
public:
    Trie(){}
    void insert(string& word){
        Trie* root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->is_string=true;
    }
    bool startsWith(string& word){
        Trie* root=this;
        for(const auto& w:word){
            if(root->next[w-'a']!=nullptr){
                root=root->next[w-'a'];
                if(root->is_string)return true;
            }
            else return false;
        }
        return false;
    }
};

class StreamChecker {
private:
    Trie* root;
    string word;
public:
    StreamChecker(vector<string>& words) {
        root=new Trie();
        for(auto word:words){
            reverse(word.begin(),word.end());
            root->insert(word);
        }
    }
    
    bool query(char letter) {
        Trie* note=root;
        word.insert(word.begin(),letter);
        return note->startsWith(word);
    }
};

int main()
{
    vector<string> words={"cd","f","kl"};
    StreamChecker streamChecker(words);
    cout<<streamChecker.query('a')<<endl;          // 返回 false
    cout<<streamChecker.query('b')<<endl;          // 返回 false
    cout<<streamChecker.query('c')<<endl;          // 返回 false
    cout<<streamChecker.query('d')<<endl;          // 返回 true，因为 'cd' 在字词表中
    cout<<streamChecker.query('e')<<endl;          // 返回 false
    cout<<streamChecker.query('f')<<endl;          // 返回 true，因为 'f' 在字词表中
    cout<<streamChecker.query('g')<<endl;          // 返回 false
    cout<<streamChecker.query('h')<<endl;          // 返回 false
    cout<<streamChecker.query('i')<<endl;          // 返回 false
    cout<<streamChecker.query('j')<<endl;          // 返回 false
    cout<<streamChecker.query('k')<<endl;          // 返回 false
    cout<<streamChecker.query('l')<<endl;          // 返回 true，因为 'kl' 在字词表中。
    return 0;
}