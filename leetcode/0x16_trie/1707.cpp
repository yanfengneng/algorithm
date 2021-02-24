#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    Trie* next[2]={nullptr};
public:
    Trie(){}

    void insert(int x)  // 在前缀树中插入值x
    {
        Trie *root=this;
        // 高位存储来Trie的前面，所以我们从左向右存储
        for(int i=30;i>=0;i--)
        {
            // 取第i位的数字，30...0
            int u=x>>i&1;
            // 若第u位为空，则创建一个新节点，然后root移动到下一个节点
            if(!root->next[u])root->next[u]=new Trie();
            root=root->next[u];
        }
    }

    int srearch(int x)  // 在前缀树中寻找 x 的最大异或值
    {
        Trie *root=this;
        // res表示最大异或值，每次res*2表示左移一位，31循环后左移了31位了，+u表示加上当前的最低位数字
        int res=0;
        for(int i=30;i>=0;i--)
        {
            int u=x>>i&1;
            // 若 x 的第 u 位存在，我们走到相反的方向去，因为异或总是|值|相反才取最大值的
            if(root->next[!u])root=root->next[!u],res=res*2+!u;
            // 相反方向的节点为空，只能顺着相同方向走了
            else root=root->next[u],res=res*2+u;
        }
        // 由于上面我们得到的异或另一个数组元素，此时我们需要将这个数组元素与x想异或得到 两个数的最大异或值
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