#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <ctime>
using namespace std;

class Solution_1 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int> track;
        set<vector<int>> result;

        //������Ȼ����ɾ���ظ���ȫ���У���Ҫ�Ż�
        /*sort(result.begin(),result.end());
        auto end_unique=unique(result.begin(),result.end());
        result.erase(end_unique,result.end());
        return result;*/
        backtrack(nums,track,result);
        return vector<vector<int>> (result.begin(),result.end());
    }
    
    void backtrack(vector<int>& nums,vector<int>& track,set<vector<int>>& result)
    {
        /*ѡ���б��ѿգ���ʾ���һ��ȫ����*/
        if(nums.empty())result.insert(track);
        else{
            for(int i=0;i<nums.size();++i)
            {
                /*choose����*/
                int n=nums[i];//�ñ������������Ȼ�unchooseҪ��
                track.push_back(n);//��ѡ��������·��
                nums.erase(nums.begin()+i);//ѡ���б�������ѡ��
                
                /*������һ������*/
                backtrack(nums,track,result);
                
                /*unchoose����*/
                nums.insert(nums.begin()+i,n);//���ѡ���ڲ��ѡ���б�
                track.pop_back();//����·���Ƴ����ѡ��
            }
        }
    }
};

class Solution_2{
public:
    //����+��֦
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<int> track(nums.begin(),nums.end());
        sort(track.begin(),track.end());
        vector<vector<int>> result;
        backtrack(track,result,0,track.size());
        return result;
        
    }
    
    /*
    ���ͬһ��εļ��㣬����������ͬ��Ԫ��ֻѡȡһ�����к������滻�����ɵȼ��ڻ���ȫ���С����磬��ǰ�����[1,2, 1, 2], ���ǿ���ֻѡȡ��һ�γ��ֵ�Ԫ����Ϊ�滻�� ���ڵ�һ��Ԫ��1�� ��һ�γ��֣�������Ϊ1��[2, 1, 2]������ȫ���е����ӣ����1��ʹ�ã����ڵڶ���Ԫ��2��2δʹ�ã�������Ϊ2��[1, 1, 2]��ȫ���е����ӣ������2��ʹ��; ���ڵ�3��Ԫ��1������ʹ�ã��������������һ��Ԫ��2������2��ʹ�ã�������
    */
    void backtrack(vector<int>& track,vector<vector<int>>& result,int index,int size)
    {
        if(index==size)result.push_back(track);
        else{
            unordered_map<int,int> mp;
            for(int i=index;i<track.size();++i)//index����ʼ���ʾѡ���б�ķ�Χ
            {
                /*��֦��ͬ��δ�Ԫ����ʹ�ö�Σ���ʹ�ñ�Ȼ���ճ��ظ�ȫ���У�����ֱ������*/
                if(mp.count(track[i]))continue;
                /*����·�������������*/
                swap(track[index],track[i]);
                /*������һ������*/
                backtrack(track,result,index+1,size);
                /*����·���Ƴ��������*/
                swap(track[index],track[i]);
                /*��Ǵ˲�����Ԫ����ʹ��һ����*/
                mp[track[i]]=1;
            }
        }
    }
};
int main()
{
    vector<int> nums{1,2,1,2};
    vector<vector<int>> result=Solution_1().permuteUnique(nums);
    for(auto it1:result){
         for(auto it2:it1)
            cout<<it2<<" ";
        cout<<endl;    
    }    
    cout<<"��֦..."<<endl; 
    result.clear();
    result=Solution_2().permuteUnique(nums);
    for(auto it1:result){
         for(auto it2:it1)
            cout<<it2<<" ";
        cout<<endl;    
    }
    system("pause");    
}