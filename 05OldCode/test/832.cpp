#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for(auto& a:A)reverse(a.begin(),a.end());
    for(auto& a:A)for(auto& x:a)if(x==0)x=1;else x=0;
    return A;
}

int main()
{
    vector<vector<int>> A={{1,1,0},{1,0,1},{0,0,0}};
    auto res=flipAndInvertImage(A);
}