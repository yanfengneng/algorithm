#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    vector<pair<int,int>> res{{3,1},{2,1},{1,1}};
    sort(res.begin(),res.end());
    for(auto it:res)
        cout<<it.first<<" "<<it.second<<endl;
    return 0;
}