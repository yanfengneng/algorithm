#include <bits/stdc++.h>
using namespace std;

vector<int> top_sort(int n,vector<vector<int>>& a)
{
    vector<vector<int>> g(n);   // �ڽӱ�
    vector<int> indegrees(n);   // ������ȱ�
    for(int i=0;i<n;++i){
        // �� j->i
        for(int j:a[i])g[j].push_back(i);
        // ���� i �Ķ�Ϊ����ָ�򶥵� i �Ķ�����
        indegrees[i]=a[i].size();
    }
    // ���Ϊ 0 �Ķ��������
    queue<int> q;
    for(int i=0;i<n;++i)
        if(!indegrees[i])q.push(i);
    // ��ʼ���� bfs�������������
    vector<int> res;
    while(q.size()){
        auto i=q.front();q.pop();
        // ���Ϊ 0 �Ķ��������������
        res.push_back(i);
        // ɾ���� i->j 
        for(int j:g[i])
            if(--indegrees[j]==0)q.push(j);
    }
    // ��Ϊ�����޻�ͼ��������ϵ���� n �����㣻�����ڻ��������������еĶ��������ȻС�� n����Ϊ���в��������Ϊ 0 �Ķ��㣬�޷����룬���д��ڻ��Ļ������������ȻС�� n
    return res.size()==n?res:vector<int>();
}

int main()
{
    vector<vector<int>> a={{},{6},{5},{6},{3,6},{},{},{}};
    auto res=top_sort(8,a);
    for(auto x:res)cout<<x<<" ";
    cout<<endl;
    return 0;
}