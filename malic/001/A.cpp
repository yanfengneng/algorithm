#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


int n;
vector<vector<int>> internals;
int res=0;

 // ��⣺����̰��
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())return {};
        // ������˵㣬�����Ҷ˵�
        // ����˵㲻ͬ������˵���С������������˵���ͬ�����Ҷ˵���С��������
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i)
        {
            // ����i����˵�<=ά��������Ҷ˵㣬��ʾ�����н�������Ҫ���кϲ�
            if(intervals[i][0]<=res.back()[1])
            {
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
            // �����޽�������ʾ�ҵ�һ���µ����䣬����ά������
            else
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        internals.push_back({l,r});
    }

    auto res=merge(internals);

    int ans=0;
    for(auto it:res)
    {
        ans+=(it[1]-it[0]+1);
    }
    cout<<ans<<endl;
    return 0;
}