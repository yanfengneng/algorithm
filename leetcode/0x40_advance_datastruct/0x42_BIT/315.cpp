#include <bits/stdc++.h>
using namespace std;

const int offset = 1e4+1,N = 2e4+10;
class Solution {
private:
    int tree[N];
    // ����Ϊ��״��������������Ĭд
    int lowbit(int x){
        return x&-x;
    }
    // ��λ��x����������1
    void add(int x,int v){
        for(int i=x;i<=N;i+=lowbit(i))
            tree[i]+=v;
    }

    // ͳ��С�ڵ���x��Ԫ�ظ���
    int sum(int x){
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=tree[i];
        return res;
    }

public:
    vector<int> countSmaller(vector<int>& a) {
        int n=a.size();
        vector<int> res(n,0);
        memset(tree,0,sizeof tree);
        // ��������ɨ�裬ͳ��ÿ�����ұ߱���С�����ĸ���
        for(int i=n-1;i>=0;i--){
            // ƫ������Ϊ�˴������ģ���a[i]ӳ�䵽λ��k
            int k=a[i]+offset;
            // ͳ��λ��k-1֮ǰ��Ԫ�ظ���
            res[i]=sum(k-1);
            // ÿ����һ�������Ͱ�k���뵽������ȥ���൱����k���λ����+1
            add(k,1);
        }
        return res;
    }
};

int main()
{
    vector<int> a{5,2,6,1};
    Solution().countSmaller(a);
    return 0;
}