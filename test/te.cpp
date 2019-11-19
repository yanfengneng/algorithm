#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size(),size=m*n;
        k%=size;
        if(k==0)return grid;
        vector<int> record;
        int a=size-k;
        for(int i=0;i<a;++i)
        {
            record.push_back(grid[i/m][i%m]);
        }
        while(a!=size)
        {
            record.insert(record.begin(),grid[a/m][a%m]);
            ++a;
        }
        vector<vector<int>> result(n,vector<int>(m));
        for(int i=0;i<n;++i)
        {
            copy(record.begin()+m*i,record.begin()+m*(i+1),result[i].begin());
        }
        return result;
    }

int mian()
{
    vector<vector<int>> grid={{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    vector<vector<int>> result=shiftGrid(grid,4);
    return 0;
}