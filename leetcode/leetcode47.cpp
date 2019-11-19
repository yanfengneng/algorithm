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

        //先排序，然后再删除重复的全排列，需要优化
        /*sort(result.begin(),result.end());
        auto end_unique=unique(result.begin(),result.end());
        result.erase(end_unique,result.end());
        return result;*/
        backtrack(nums,track,result);
        return vector<vector<int>> (result.begin(),result.end());
    }
    
    void backtrack(vector<int>& nums,vector<int>& track,set<vector<int>>& result)
    {
        /*选择列表已空，表示完成一个全排列*/
        if(nums.empty())result.insert(track);
        else{
            for(int i=0;i<nums.size();++i)
            {
                /*choose过程*/
                int n=nums[i];//用变量存起来，等会unchoose要用
                track.push_back(n);//该选择加入决策路径
                nums.erase(nums.begin()+i);//选择列表擦除这个选择
                
                /*进入下一步决策*/
                backtrack(nums,track,result);
                
                /*unchoose过程*/
                nums.insert(nums.begin()+i,n);//这个选择在插回选择列表
                track.pop_back();//决策路径移除这个选择
            }
        }
    }
};

class Solution_2{
public:
    //回溯+剪枝
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<int> track(nums.begin(),nums.end());
        sort(track.begin(),track.end());
        vector<vector<int>> result;
        backtrack(track,result,0,track.size());
        return result;
        
    }
    
    /*
    针对同一层次的计算，对连续的相同的元素只选取一个进行后续的替换，即可等价于基础全排列。例如，当前层次是[1,2, 1, 2], 我们可以只选取第一次出现的元素作为替换： 对于第一个元素1， 第一次出现，则其结果为1与[2, 1, 2]的所有全排列的连接，标记1已使用；对于第二个元素2，2未使用，则其结果为2与[1, 1, 2]的全排列的连接，并标记2已使用; 对于第3个元素1，其已使用，跳过；对于最后一个元素2，由于2已使用，跳过。
    */
    void backtrack(vector<int>& track,vector<vector<int>>& result,int index,int size)
    {
        if(index==size)result.push_back(track);
        else{
            unordered_map<int,int> mp;
            for(int i=index;i<track.size();++i)//index的起始点表示选择列表的范围
            {
                /*剪枝：同层次此元素已使用多次，在使用必然会照成重复全排列，所以直接跳过*/
                if(mp.count(track[i]))continue;
                /*决策路径加上这个决策*/
                swap(track[index],track[i]);
                /*进入下一步决策*/
                backtrack(track,result,index+1,size);
                /*决策路径移除这个决策*/
                swap(track[index],track[i]);
                /*标记此层次这个元素已使用一次了*/
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
    cout<<"剪枝..."<<endl; 
    result.clear();
    result=Solution_2().permuteUnique(nums);
    for(auto it1:result){
         for(auto it2:it1)
            cout<<it2<<" ";
        cout<<endl;    
    }
    system("pause");    
}