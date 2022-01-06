#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[5];
    scanf("%s",str);
    vector<int> vec;
    int x;
    while(cin>>x)vec.push_back(x);
    if(str[0]=='A')sort(vec.begin(),vec.end());
    else sort(vec.rbegin(),vec.rend());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int v:vec)cout<<v<<" ";
    cout<<endl;
    return 0;
}