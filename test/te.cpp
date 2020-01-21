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
    int a=1;
    int *b=&a;
    cout<<b<<endl;
    cout<<&a<<endl;
    return 0;
}