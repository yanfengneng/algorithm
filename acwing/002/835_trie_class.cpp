#pragma GCC optimize(2)
#include <iostream>
#include <string>
using namespace std;

class Trie
{
private:
    bool is_string=false;
    Trie *next[26]={nullptr};
    int count=0;
public:
    Trie(){}

    void insert(const string& word)//插入单词
    {
        Trie *root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->count++;
        root->is_string=true;
    }

    int search(const string& word)//查找单词
    {
        Trie* root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)return false;
            root=root->next[w-'a'];
        }
        return root->count;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Trie root;
    int n;
    cin>>n;
    while(n--)
    {
        string op,str;
        cin>>op>>str;
        if(op[0]=='I')root.insert(str);
        else cout<<root.search(str)<<endl;
    }
    return 0;
}