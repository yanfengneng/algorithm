#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    string s="xiaonengcaoji";
    int a[26];
    memset(a,0,sizeof(a));
    for(auto c:s)
        a[c-'a']++;
}