#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> dict;
    // ˫�� BFS
    int ladderLength(string start, string end, vector<string>& a) {
        // ������е��ʵ��ֵ�
        for(auto s:a)dict.insert(s);
        if(!dict.count(end))return 0;
        // ds ��ʾ����㵽��չ���ĵ�ľ��룬de ��ʾ�յ㵽��չ����ľ���
        unordered_map<string,int> ds,de;
        // qs ��ʾ����㿪ʼ�ѣ�qe ��ʾ���յ㿪ʼ�ѡ���Ҫ������������Ķ��У������洢״̬
        queue<string> qs,qe;
        // �洢��ʼλ�ú���ʼ����
        qs.push(start),ds[start]=1;
        qe.push(end),de[end]=1;
        // ֻҪ�������ж���Ϊ��ʱ�����ܼ�����չ��������һ��Ϊ�գ����߶�Ϊ�գ�˵��s e��һ������ͨ�ģ������ڽ���������ֻҪ�м�����ͨ�ģ���һ�����Ա��ȥ��
        while(qs.size()&&qe.size())
        {
            int t;
            // ÿ��ѡ���״̬���ٵĶ��п�ʼ������չ������������ʱ�临�Ӷȡ�
            if(qs.size()<=qe.size())t=extend(qs,ds,de);
            else t=extend(qe,de,ds);
            if(t)return t;
        }
        return 0;
    }

    int extend(queue<string>& q,unordered_map<string,int>& ds,unordered_map<string,int>& de)
    {
        int span=q.size();
        // ÿ����չ��Ҫ����ǰ���������еĵ������չ��������֤�������·��
        while(span--)
        {
            auto t=q.front();q.pop();
            // ����״̬����չ����ö�ٱ��滻�ַ���λ�ã���ö��ʣ�� 25 ���ַ���������չ�����µ���
            for(int i=0,n=t.size();i<n;++i)
            {
                string copy=t;
                for(int j=0;j<26;++j)
                {
                    // ��ͬ�ַ������ñ��滻
                    if('a'+j==t[i])continue;
                    // �滻Ϊ���ַ� j
                    copy[i]='a'+j;
                    // ����չ����״̬�ٶ��� e �б�ʾ�����������ˣ�����Ϊ start->t-copy->end
                    if(de.count(copy))return ds[t]+de[copy];
                    // ��״̬�����ֵ��л��߸�״̬�Ѿ������ʹ��ˣ���ֱ�ӽ�������
                    if(!dict.count(copy)||ds.count(copy))continue;
                    // ������㵽��״̬ copy �ľ��룬���������
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