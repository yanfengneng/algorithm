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
        // ȷ���ֽ��
        int i=l-1,j=r+1,x=q[l+r>>1];
        // ��������
        while(i<j)
        {
            // �������У�Ѱ�Ҵ��ڵ���x��ֵ
            do ++i;while(q[i]<x);
            // �������У�Ѱ��С�ڵ���x��ֵ
            do --j;while(q[j]>x);
            if(i<j)swap(q[i],q[j]);
        }
        // �ݹ鴦��������������
        quick_sort(q,l,j),quick_sort(q,j+1,r);
    }
};