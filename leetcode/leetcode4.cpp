#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,k=0,m=nums1.size(),n=nums2.size();
        vector<int> nums(m+n);
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]){
                nums[k++]=nums1[i++];
            }
            else{
                nums[k++]=nums2[j++];
            }
        }
        if(i==m){
            while(j<n){
                nums[k++]=nums2[j++];
            }
        }
        if(j==n){
            while(i<m){
                nums[k++]=nums1[i++];
            }
        }
        //m+nÎªÆæÊý
        if((m+n)&1)return nums[(m+n)/2];
        return (nums[(m+n)/2-1]+nums[(m+n)/2])/2.0;
    }
};

int main()
{
    vector<int> nums1{1,3},nums2{2};
    cout<<Solution().findMedianSortedArrays(nums1,nums2)<<endl;
}