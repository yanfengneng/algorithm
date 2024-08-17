#include <bits/stdc++.h>
using namespace std;

using LL = long long;
int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        // 存储灯所在行、列、主对角线、副对角线的光的数量
        unordered_map<int,int> row,col,left,right;
        // 用来存储灯的坐标点的，便于在询问的时候，删除光的八个方向包括该光本身是否存在灯，然后将存在的灯熄灭
        set<LL> point; 
        LL N=n;
        auto change=[&](int x,int y,int c){
            row[x]+=c,col[y]+=c,right[x-y]+=c,left[x+y]+=c;
        };
        // 遍历灯：存储以上数据结构
        for(vector<int>& l:lamps){
            int x=l[0],y=l[1];
            // 重复点直接跳过
            if(point.count(x*N+y))continue;
            point.insert(x*N+y);
            change(x,y,1);
        }
        vector<int> res;
        for(vector<int>& q:queries){
            int x=q[0],y=q[1];
            // 判断(x,y)所在行、列、对角线是否存在光
            if(row[x]||col[y]||right[x-y]||left[x+y])res.push_back(1);
            else {res.push_back(0);continue;}
            // 然后将光所在点的8个方向包括该点本身的所有灯进行关闭
            for(int i=0;i<9;++i){
                int nx=x+dir[i][0],ny=y+dir[i][1];
                if(nx<0||ny<0||nx>=n||ny>=n)continue;
                // 灯存在，则进行删除灯，并关闭行列对角线上的光
                if(point.count(nx*N+ny)){
                    point.erase(nx*N+ny);
                    change(nx,ny,-1);
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> lamps={{0,0},{4,4}},queries={{1,1},{1,0}};
    vector<int> res=Solution().gridIllumination(5,lamps,queries);
    for(int r:res)cout<<r<<" ";
    cout<<endl;
    return 0;
}