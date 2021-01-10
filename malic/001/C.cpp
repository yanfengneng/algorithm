#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string str;
    cin>>str;
    stack<char> s;
    for(int i=0;i<str.size();++i)
    {
        if(str[i]!='<')s.push(str[i]);
        else s.pop();
    }

    string res;
    while(!s.empty())
    {
        res+=s.top();
        s.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return 0;
}