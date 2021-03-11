#include <bits/stdc++.h>
using namespace std;

using LL = long long;

bool isOK(string a)
{
    int l=0,r=a.size()-1;
    while(l<r)if(a[l++]!=a[r--])return false;
    return true;
}

int main()
{
    string n;
    cin>>n;
    int cnt=0;
    while(!isOK(n))
    {
        cnt++;
        string m(n.rbegin(),n.rend());
        n=to_string(stoll(m)+stoll(n));
    }
    cout<<cnt<<" "<<stoi(n)<<endl;
    return 0;
}