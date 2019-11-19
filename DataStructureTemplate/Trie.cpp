#include <iostream>
#include <string>
using namespace std;

class Trie
{
private:
    bool is_string=false;
    Trie *next[26]={nullptr};
public:
    Trie(){}

    void insert(const string& word)//���뵥��
    {
        Trie *root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->is_string=true;
    }

    bool search(const string& word)//���ҵ���
    {
        Trie* root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)return false;
            root=root->next[w-'a'];
        }
        return root->is_string;
    }

    bool startsWith(string prefix)//����ǰ׺
    {
        Trie* root=this;
        for(const auto& p:prefix){
            if(root->next[p-'a']==nullptr)return false;
            root=root->next[p-'a'];
        }
        return true;
    }
};

int main()
{
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;
    cout<<trie->startsWith("a")<<endl;
    system("pause");
    return 0;
}