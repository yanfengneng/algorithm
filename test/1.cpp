#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<pair<int,int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==1&&n==1){
            return true;
        }
        int mm=3*m,nn=3*n;
        vector<vector<int>>matrix(3*m,vector<int>(3*n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int t=0;t<=2;t++){
                        matrix[3*i+1][3*j+t]=1;
                    }
                }
                else if(grid[i][j]==2){
                    for(int t=0;t<=2;t++){
                        matrix[3*i+t][3*j+1]=1;
                    }
                }
                else if(grid[i][j]==3){
                    matrix[3*i+1][3*j]=1;
                    matrix[3*i+1][3*j+1]=1;
                    matrix[3*i+2][3*j+1]=1;
                }
                else if(grid[i][j]==4){
                    matrix[3*i+1][3*j+1]=1;
                    matrix[3*i+1][3*j+2]=1;
                    matrix[3*i+2][3*j+1]=1;
                }
                else if(grid[i][j]==5){
                    matrix[3*i][3*j+1]=1;
                    matrix[3*i+1][3*j+1]=1;
                    matrix[3*i+1][3*j]=1;
                }
                else if(grid[i][j]==6){
                    matrix[3*i+1][3*j+1]=1;
                    matrix[3*i][3*j+1]=1;
                    matrix[3*i+1][3*j+2]=1;
                }
            }
        }
        queue<pair<int,int>>Q;
        vector<vector<bool>>visit(3*m,vector<bool>(3*n,false));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(matrix[i][j]){
                    Q.push({i,j});
                    visit[i][j]=true;
                }
            }
        }
        while(!Q.empty()){
            auto p=Q.front();
            Q.pop();
            for(auto d:dir){
                int x=p.first+d.first;
                int y=p.second+d.second;
                if(x>=0&&x<mm&&y>=0&&y<nn&&!visit[x][y]&&matrix[x][y]){
                    visit[x][y]=true;
                    Q.push({x,y});
                    if(x/3==m-1&&y/3==n-1){
                    return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    //范围：[-32768,32757]，给带符号数赋予一个超过它范围的数，程序可能正常运行，崩溃，或者产生垃圾数据
    //而这里可以正常运行，说明程序把65535转换为二进制数了1...1，然后程序把它作为负数的补码，保留符号位1，算出最后的真值为-1(10...01)
    short a=65535;
    cout<<a<<endl;
    cout<<"我好帅"<<endl;
}