#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
class Trie{
private:
    bool is_string;
    Trie *next[26];
public:
    Trie(){
        is_string=false;
        memset(next,0,sizeof(next));
    }
    
    void insert(string word){
        Trie *root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->is_string=true;
    }
    
    bool search(string word,int index,int count){
        Trie *root=this;
        for(int i=index;i<word.size();++i){
            if(root->next[word[i]-'a']==nullptr)return false;//word��ĳ���ַ�����ǰ׺����
            root=root->next[word[i]-'a'];
            if(root->is_string){//����ĳ������β
                if(i==word.size()-1)return count>=1;//count����������Ϊ2���������������ֻ��һ�����ʣ���count��ֵ����Ϊ0
                if(search(word,i+1,count+1))return true;//����ƥ����һ������
                else continue;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie *root=new Trie();
        for(const auto &word:words){
            root->insert(word);
        }
        vector<string> result;
        for(const auto &word:words){
            if(root->search(word,0,0))
                result.push_back(word);
        }
        return result;
    }
};

int main()
{
    vector<string> v={"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vector<string> result=Solution().findAllConcatenatedWordsInADict(v);
    for(auto r:result)
        cout<<r<<" ";
    cout<<endl;
    system("pause");
}
