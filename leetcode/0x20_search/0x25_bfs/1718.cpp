#include <bits/stdc++.h>
using namespace std;

bool visited[45];

class Solution {
public:
    vector<int> res,trace;
    vector<int> constructDistancedSequence(int n) {
        memset(visited,0,sizeof visited);
        res.resize(2*n-1),trace.resize(2*n-1);
        backtrace(0,n);
        return res;
    }

    bool backtrace(int idx,int n)
    {
        if(idx==2*n-1)
        {
            res=max(res,trace);
            return true;
        }
        if(trace[idx])return backtrace(idx+1,n);
        // �Ӵ�С����ö�٣��ҵ���һ�����н⣬�����ֵ������ģ�����ture������
        for(int i=n;i>=1;--i)
        {
            if(!visited[i])
            {
                if(i==1)
                {
                    /*choose���̣��������·��*/
                    trace[idx]=1,visited[i]=1;
                    /*������һ�ξ���*/
                    if(backtrace(idx+1,n))return true;
                    /*unchoose���̣��Ƴ��þ���*/
                    trace[idx]=0,visited[i]=0;
                    return false;
                }
                else
                {
                    // ��֦��i̫����
                    if(idx+i>=2*n-1)continue;
                    // ��֦��idx+i��λ�ò��ܷ�Ԫ����
                    if(trace[i+idx])continue;
                    visited[i]=1,trace[idx]=i,trace[idx+i]=i;
                    if(backtrace(idx+1,n))return true;
                    visited[i]=0,trace[idx]=0,trace[idx+i]=0;
                }
            }
        }
        return false;
    }
};

int main()
{
    auto res=Solution().constructDistancedSequence(3);
    for(auto r:res)cout<<r<<" ";
    cout<<endl;
    return 0;
}