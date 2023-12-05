#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> father; // ����
    vector<int> len;    // ���Ĵ�С
public:
    UnionFind(int n)    // ���캯����ʼ������
    {
        father.resize(n),len.resize(n);
        for(int i=0;i<n;++i)
        {
            father[i]=i;    // ��ʼ��ʱ���ڵ�ָ����
            len[i]=1;       // ��ʼ��ʱÿ������СΪ1
        }
    }

    int find(int x)     // ��ѯ���ĸ�
    {
        // �ڲ�ѯ���и��ڵ�����У�˳�����·��ѹ��
        if(father[x]!=x)return father[x]=find(father[x]);
        else return x;
    }

    void merge(int x,int y) // �ϲ�x��y�����ļ���
    {
        x=find(x),y=find(y);
        if(x==y)return;     // x��yΪͬһ���ϲ���Ҫ�ϲ�
        // ���Ƚ��кϲ���С������Ⱥϲ�
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
        // 1���ȳ�ʼ��[0,n-1]��id�Ĳ��鼯
        UnionFind uf(n);
        // 2����rec1����¼<���䣬����id>����������ͬ������ʱ�����ǰ�id���кϲ�����ʾΪͬһ�ͻ�
        unordered_map<string,int> rec1;
        for(int i=0;i<n;++i)
        {   
            // ����idΪi�Ŀͻ�������
            for(int j=1;j<accounts[i].size();++j)
            {
                // �ж��Ƿ����ظ����䡣û�г������id��emil��¼��map�У��������ظ����䣬�����id�ĺϲ�
                string emil=accounts[i][j];
                if(rec1.find(emil)==rec1.end())rec1[emil]=i;
                else uf.merge(i,rec1[emil]);
            }
        }
        // 3������һ��rec2����¼<��ͨ�����ڵ�id�������б�>
        unordered_map<int,vector<string>> rec2;
        for(auto &[k,v]:rec1)// ��ͬһ�����е��������һ�������Ѿ������˼��ϵĺϲ������Բ�������ظ�������
        {
            rec2[uf.find(v)].emplace_back(k);
        }
        // 4������rec2�����õ������
        vector<vector<string>> res;
        for(auto& [k,v]:rec2)
        {
            vector<string> account;
            // ���ͻ���������ӽ�ȥ
            account.push_back(accounts[k][0]);
            // �������������
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