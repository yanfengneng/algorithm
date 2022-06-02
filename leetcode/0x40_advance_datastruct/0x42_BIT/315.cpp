#include <bits/stdc++.h>
using namespace std;

const int offset = 1e4+1,N = 2e4+10;
class Solution {
private:
    int tree[N];
    // 以下为树状数组三个函数的默写
    int lowbit(int x){
        return x&-x;
    }
    // 在位置x上增加数量1
    void add(int x,int v){
        for(int i=x;i<=N;i+=lowbit(i))
            tree[i]+=v;
    }

    // 统计小于等于x的元素个数
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
        // 从右向左扫描，统计每个数右边比它小的数的个数
        for(int i=n-1;i>=0;i--){
            // 偏移量是为了处理负数的，将a[i]映射到位置k
            int k=a[i]+offset;
            // 统计位置k-1之前的元素个数
            res[i]=sum(k-1);
            // 每处理一个数，就把k加入到集合中去，相当于在k这个位置上+1
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