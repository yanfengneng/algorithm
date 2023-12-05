#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> father; // 父亲
    vector<int> len;    // 树的大小
public:
    UnionFind(int n)    // 构造函数初始化对象
    {
        father.resize(n),len.resize(n);
        for(int i=0;i<n;++i)
        {
            father[i]=i;    // 初始化时父节点指向本身
            len[i]=1;       // 初始化时每个树大小为1
        }
    }

    int find(int x)     // 查询树的根
    {
        // 在查询所有父节点过程中，顺便进行路径压缩
        if(father[x]!=x)return father[x]=find(father[x]);
        else return x;
    }

    void merge(int x,int y) // 合并x和y所属的集合
    {
        x=find(x),y=find(y);
        if(x==y)return;     // x和y为同一集合不需要合并
        // 按秩进行合并，小秩向大秩合并
        if(len[x]<len[y])
        {
            father[x]=y;
            len[y]+=len[x];
        } 
        else
        {
            father[y]=x;
            len[x]+=len[y];
        }       
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        // 1、先初始化[0,n-1]号id的并查集
        UnionFind uf(n);
        // 2、用rec1来记录<邮箱，邮箱id>，当出现相同的邮箱时，我们把id进行合并，表示为同一客户
        unordered_map<string,int> rec1;
        for(int i=0;i<n;++i)
        {   
            // 遍历id为i的客户的邮箱
            for(int j=1;j<accounts[i].size();++j)
            {
                // 判断是否发现重复邮箱。没有出现则把id和emil记录在map中，出现了重复邮箱，则进行id的合并
                string emil=accounts[i][j];
                if(rec1.find(emil)==rec1.end())rec1[emil]=i;
                else uf.merge(i,rec1[emil]);
            }
        }
        // 3、再用一个rec2来记录<联通量根节点id，邮箱列表>
        unordered_map<int,vector<string>> rec2;
        for(auto &[k,v]:rec1)// 将同一集合中的邮箱放在一起，由于已经进行了集合的合并，所以不会出现重复的邮箱
        {
            rec2[uf.find(v)].emplace_back(k);
        }
        // 4、遍历rec2，来得到最后结果
        vector<vector<string>> res;
        for(auto& [k,v]:rec2)
        {
            vector<string> account;
            // 将客户的姓名添加进去
            account.push_back(accounts[k][0]);
            // 将邮箱进行排序
            sort(v.begin(),v.end());
            account.insert(account.end(),v.begin(),v.end());
            res.push_back(account);
        }
        return res;
    }
};

int main()
{
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    auto res=Solution().accountsMerge(accounts);

}