#include <bits/stdc++.h>
using namespace std;

using LL = long long;
int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        // �洢�������С��С����Խ��ߡ����Խ��ߵĹ������
        unordered_map<int,int> row,col,left,right;
        // �����洢�Ƶ������ģ�������ѯ�ʵ�ʱ��ɾ����İ˸���������ùⱾ���Ƿ���ڵƣ�Ȼ�󽫴��ڵĵ�Ϩ��
        set<LL> point; 
        LL N=n;
        auto change=[&](int x,int y,int c){
            row[x]+=c,col[y]+=c,right[x-y]+=c,left[x+y]+=c;
        };
        // �����ƣ��洢�������ݽṹ
        for(vector<int>& l:lamps){
            int x=l[0],y=l[1];
            // �ظ���ֱ������
            if(point.count(x*N+y))continue;
            point.insert(x*N+y);
            change(x,y,1);
        }
        vector<int> res;
        for(vector<int>& q:queries){
            int x=q[0],y=q[1];
            // �ж�(x,y)�����С��С��Խ����Ƿ���ڹ�
            if(row[x]||col[y]||right[x-y]||left[x+y])res.push_back(1);
            else {res.push_back(0);continue;}
            // Ȼ�󽫹����ڵ��8����������õ㱾������еƽ��йر�
            for(int i=0;i<9;++i){
                int nx=x+dir[i][0],ny=y+dir[i][1];
                if(nx<0||ny<0||nx>=n||ny>=n)continue;
                // �ƴ��ڣ������ɾ���ƣ����ر����жԽ����ϵĹ�
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