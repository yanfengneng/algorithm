#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        int n=arr.size();
        quick_sort(arr,0,n-1);
        for(int i=1;i<n;++i)
            if(arr[i]-arr[i-1]!=arr[1]-arr[0])
                return false;
        return true;
    }

    void quick_sort(vector<int>& q,int l,int r)
    {
        if(l>=r)return;
        // 确定分界点
        int i=l-1,j=r+1,x=q[l+r>>1];
        // 划分区间
        while(i<j)
        {
            // 在左序列，寻找大于等于x的值
            do ++i;while(q[i]<x);
            // 在右序列，寻找小于等于x的值
            do --j;while(q[j]>x);
            if(i<j)swap(q[i],q[j]);
        }
        // 递归处理左右两个序列
        quick_sort(q,l,j),quick_sort(q,j+1,r);
    }
};