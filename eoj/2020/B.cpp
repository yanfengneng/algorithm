#include <bits/stdc++.h>
using namespace std;

int a[5];

void solve(string str)
{
    if(str.empty())return;
    else if(str[0]=='I'){
        a[str[3]-'A']=stoi(str.substr(6));
    }
    else if(str[0]=='M'&&str[1]=='O'){
        a[str[4]-'A']=a[str[7]-'A'];
    }
    else if(str[0]=='A'){
        a[str[4]-'A']+=a[str[7]-'A'];
    }
    else if(str[0]=='S'){
        a[str[4]-'A']-=a[str[7]-'A'];
    }
    else if(str[0]=='M'&str[1]=='U'){
        a[str[4]-'A']*=a[str[7]-'A'];
    }
    else if(str[0]=='D'){
        a[str[4]-'A']/=a[str[7]-'A'];
    }
    else cout<<a[str[4]-'A']<<endl;
}

int main()
{
    string str;
    while(getline(cin,str))
    {
        solve(str);
    }
    return 0;
}