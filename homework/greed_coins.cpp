#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount)return 0;
        int res=INT_MAX;
        sort(coins.rbegin(),coins.rend());//�ɴ�С���򣬱���̰�ĵ�ѡȡ��ֵ�����Ǯ
        dfs(coins,amount,0,0,res);
        return res==INT_MAX?-1:res;
    }

    //����Ѱ�����������������Ǯ����k��ʾһ�ο���coins[i]���������������治�ܴﵽ��Ǯ��ȫ�һ����߶һ�����Ǯ������resʱ����������k--���֦
    //index��������coins��count����ͳ�����õ���Ǯ��
    void dfs(vector<int>& coins,int amount,int count,int index,int& res){
        if(amount==0){res=min(res,count);return;}
        if(index==coins.size())return;
        for(int k=amount/coins[index];k>=0&&k+count<res;--k){//k����ö��������Ǯ�һ���״̬��
            dfs(coins,amount-k*coins[index],count+k,index+1,res);
        }
    }
};

int main()
{
    vector<int> c1={1,2,5},c2={2};
    cout<<Solution().coinChange(c1,11)<<endl;
    cout<<Solution().coinChange(c2,3)<<endl;
    system("pause");
}