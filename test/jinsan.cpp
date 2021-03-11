#include <bits/stdc++.h>
using namespace std;

map<char,int> mp;

int main()
{
    string str;
    while(getline(cin,str)){
        for(int i=0;i<str.length();++i){
            if(++mp[str[i]]&&isalpha(str[i])){
                cout<<str[i]<<endl;
                return 0;
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}