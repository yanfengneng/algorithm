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
    cout<<streamChecker.query('a')<<endl;          // ���� false
    cout<<streamChecker.query('b')<<endl;          // ���� false
    cout<<streamChecker.query('c')<<endl;          // ���� false
    cout<<streamChecker.query('d')<<endl;          // ���� true����Ϊ 'cd' ���ִʱ���
    cout<<streamChecker.query('e')<<endl;          // ���� false
    cout<<streamChecker.query('f')<<endl;          // ���� true����Ϊ 'f' ���ִʱ���
    cout<<streamChecker.query('g')<<endl;          // ���� false
    cout<<streamChecker.query('h')<<endl;          // ���� false
    cout<<streamChecker.query('i')<<endl;          // ���� false
    cout<<streamChecker.query('j')<<endl;          // ���� false
    cout<<streamChecker.query('k')<<endl;          // ���� false
    cout<<streamChecker.query('l')<<endl;          // ���� true����Ϊ 'kl' ���ִʱ��С�
    return 0;
}