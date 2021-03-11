#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    char c;
    cin>>c;
    int cnt=0;
    for(int i=0;i<str.size();++i){
        if(c==str[i]||int(c)==int(str[i]^32))cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}