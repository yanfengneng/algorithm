#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //���1����̬�滮��ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)
    //˼·��354. ����˹���޵���һģһ����������Ŀ�������ˣ�����αװ��
    int findLongestChain_1(vector<vector<int>>& pairs) {
        if(pairs.empty())return 0;
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b){
            return (a[0]==b[0]&&a[1]<b[1])||(a[0]<b[0]);
        });
        int n=pairs.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }

     //�ⷨ2����̬�滮+���ַ���ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(n)
    int findLongestChain_2(vector<vector<int>>& pairs){
        if(pairs.empty())return 0;
        sort(pairs.begin(),pairs.end(),[](const auto& a,const auto& b){
            return (a[0]<b[0])||(a[0]==b[0]&&a[1]<b[1]);
        });
        vector<vector<int>> dp;
        for(auto& p:pairs){
            //���ַ�Ѱ�Ҵ��ڵ���p[0]����Сֵdp[i][1]
            int left=0,right=dp.size();
            while(left<right){//����whileѭ��������������2��Ԫ�أ��˳�ѭ���ļ�ֵֻ��0��size
                int mid=left+((right-left)>>1);
                if(dp[mid][1]>=p[0])right=mid;
                else left=mid+1;
            }
            //dp[size-1][1]<p[0]���������������ĳ���
            if(left>=dp.size())dp.emplace_back(p);
            //dp[left][1]���ڣ����ڣ�p[0]ͬʱҲ����p[1]����ô���Ǹ���dp[left]Ϊp���������Խ�left��С���Ա��γ����������
            else if(dp[left][1]>p[1])dp[left]=p;
        }
        return dp.size();
    }
};

int main()
{
    vector<vector<int>> pairs={{1,2}, {2,3}, {3,4}};
    cout<<Solution().findLongestChain_2(pairs)<<endl;

}