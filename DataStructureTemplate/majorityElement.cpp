#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> nums)
{
    int majority=-1,count=0;

    //第一次遍历：选出候选人
    for(int num:nums)
    {
        if(count==0){
            majority=num;
            count++;
        }
        else{
            if(num==majority)count++;
            else count--;
        }
    }

    if(count<=0)return -1;
    count=0;

    //第二次遍历：确定候选人的票数是否满足
    for(int num:nums){
        if(num==majority)count++;
    }
    if(count>nums.size()/2)return majority;
    else return -1;
}

int main()
{
    vector<int> nums={1,0,3,2,2,2,2,2,6};
    cout<<majorityElement(nums)<<endl;
    system("pause");
}