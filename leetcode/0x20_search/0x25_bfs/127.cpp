#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> dict;
    // 双向 BFS
    int ladderLength(string start, string end, vector<string>& a) {
        // 存放所有单词的字典
        for(auto s:a)dict.insert(s);
        if(!dict.count(end))return 0;
        // ds 表示从起点到扩展到的点的距离，de 表示终点到扩展到点的距离
        unordered_map<string,int> ds,de;
        // qs 表示从起点开始搜，qe 表示从终点开始搜。需要建立两个方向的队列，用来存储状态
        queue<string> qs,qe;
        // 存储起始位置和起始距离
        qs.push(start),ds[start]=1;
        qe.push(end),de[end]=1;
        // 只要两个队列都不为空时，才能继续扩展。若其中一个为空，或者都为空，说明s e是一定不连通的，不存在交集；否则只要中间是连通的，就一定可以变过去。
        while(qs.size()&&qe.size())
        {
            int t;
            // 每次选择从状态数少的队列开始进行扩展，这样来降低时间复杂度。
            if(qs.size()<=qe.size())t=extend(qs,ds,de);
            else t=extend(qe,de,ds);
            if(t)return t;
        }
        return 0;
    }

    int extend(queue<string>& q,unordered_map<string,int>& ds,unordered_map<string,int>& de)
    {
        int span=q.size();
        // 每次扩展需要将当前队列中所有的点进行扩展，这样保证搜索最短路径
        while(span--)
        {
            auto t=q.front();q.pop();
            // 进行状态的扩展：先枚举被替换字符的位置，再枚举剩余 25 个字符，构成扩展到的新单词
            for(int i=0,n=t.size();i<n;++i)
            {
                string copy=t;
                for(int j=0;j<26;++j)
                {
                    // 相同字符，不用被替换
                    if('a'+j==t[i])continue;
                    // 替换为新字符 j
                    copy[i]='a'+j;
                    // 若扩展到的状态再队列 e 中表示两队列相遇了，距离为 start->t-copy->end
                    if(de.count(copy))return ds[t]+de[copy];
                    // 新状态不在字典中或者该状态已经被访问过了，就直接进行跳过
                    if(!dict.count(copy)||ds.count(copy))continue;
                    // 更新起点到新状态 copy 的距离，并加入队列
                    ds[copy]=ds[t]+1,q.push(copy);
                }
            }
        }
        return 0;
    }
};

int main()
{
    string start="hbo",end="qbx";
    vector<string> a={"abo","hco","hbw","ado","abq","hcd","hcj","hww","qbq","qby","qbz","qbx","qbw"};
    cout<<Solution().ladderLength(start,end,a)<<endl;
    return 0;
}