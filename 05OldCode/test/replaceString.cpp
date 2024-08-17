#include <iostream>
#include <string>
using namespace std;

string replaceStr(string t,string p,string s)
{
    while(t.find(p)!=string::npos)
    {
        t.replace(t.find(p),p.size(),s);
    }
    return t;
}

int main()
{
    string t="123123123123",p="123",s="4567";
    string test=replaceStr(t,p,s);
    cout<<test<<endl;
}