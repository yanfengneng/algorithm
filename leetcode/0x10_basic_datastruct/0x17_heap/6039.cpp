#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
using LL = long long;
class Solution {
public:
    // ��x��1����ʵ���Ǹ�����������(x+1)/x=1+1/x�������xԽ������ԽС������ÿ��ѡ��x��С�ģ�Ȼ������+1
    int maximumProduct(vector<int>& a, int k) {
        // ʹ��С���ѣ�k��ÿ��ȡ��Сֵ����+1
        priority_queue<int,vector<int>,greater<int>> pq(a.begin(),a.end());
        while(k){
            // ÿ��ȡ��Сֵ�ʹ���Сֵ��Ȼ������Сֱֵ�Ӽӵ�����Сֵ�����λ��
            int x=pq.top();pq.pop();
            int y=pq.top(),cnt=y-x; // cntΪx�ӵ�y��Ҫ�����Ĵ���
            if(cnt==0)x++,k--;      // ��Сֵ�ʹ���Сֵ��ȣ��������Сֵ+1���ɣ�ͬʱk��1
            else if(cnt<k)x+=cnt,k-=cnt; // x���ӵ�y�Ĵ���С��k����ֱ�ӽ�x���ӵ�y��ͬʱ��k��cnt
            else x+=k,k=0; // x���ӵ�y�Ĵ������ڵ���k����ôx�������k���ˣ�ͬʱk��Ϊ0
            pq.push(x);
        }
        LL res=1;
        while(pq.size()){
            res=res*pq.top()%mod;
            pq.pop();
        }
        return res;
    }
};

int main()
{
    vector<int> v={0,4};
    cout<<Solution().maximumProduct(v,5)<<endl;
    return 0;
}