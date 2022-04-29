#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    Trie* next[2]={nullptr};
public:
    Trie(){}

    void insert(int x)  // ��ǰ׺���в���ֵx
    {
        Trie *root=this;
        // ��λ�洢��Trie��ǰ�棬�������Ǵ������Ҵ洢
        for(int i=30;i>=0;i--)
        {
            // ȡ��iλ�����֣�30...0
            int u=x>>i&1;
            // ����uλΪ�գ��򴴽�һ���½ڵ㣬Ȼ��root�ƶ�����һ���ڵ�
            if(!root->next[u])root->next[u]=new Trie();
            root=root->next[u];
        }
    }

    int srearch(int x)  // ��ǰ׺����Ѱ�� x ��������ֵ
    {
        Trie *root=this;
        // res��ʾ������ֵ��ÿ��res*2��ʾ����һλ��31ѭ����������31λ�ˣ�+u��ʾ���ϵ�ǰ�����λ����
        int res=0;
        for(int i=30;i>=0;i--)
        {
            int u=x>>i&1;
            // �� x �ĵ� u λ���ڣ������ߵ��෴�ķ���ȥ����Ϊ�������|ֵ|�෴��ȡ���ֵ��
            if(root->next[!u])root=root->next[!u],res=res*2+!u;
            // �෴����Ľڵ�Ϊ�գ�ֻ��˳����ͬ��������
            else root=root->next[u],res=res*2+u;
        }
        // �����������ǵõ��������һ������Ԫ�أ���ʱ������Ҫ���������Ԫ����x�����õ� ��������������ֵ
        res^=x;
        return res;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        set<pair<pair<int,int>,int>> record;
        int n=queries.size();
        for(int i=0;i<n;++i)
            record.insert({{queries[i][1],queries[i][0]},i});
        
        int i=0;
        vector<int> res(n);
        Trie *root=new Trie();
        for(auto r:record)
        {
            while(i<nums.size()&&nums[i]<=r.first.first)root->insert(nums[i++]);
            if(r.first.first<nums[0])res[r.second]=-1;
            else res[r.second]=root->srearch(r.first.second);
        }
        return res;
    }
};

int main()
{
    vector<int> nums={0,1,2,3,4};
    vector<vector<int>> queries={{3,1},{1,3},{5,6}};
    auto res=Solution().maximizeXor(nums,queries);
    for(auto r:res)cout<<r<<" ";
    cout<<endl;
    return 0;
}