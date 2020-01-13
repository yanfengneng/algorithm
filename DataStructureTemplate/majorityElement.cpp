#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> nums)
{
    int majority=-1,count=0;

    //��һ�α�����ѡ����ѡ��
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

    //�ڶ��α�����ȷ����ѡ�˵�Ʊ���Ƿ�����
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