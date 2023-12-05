#include <bits/stdc++.h>
using namespace std;

int check(string a, string b)
{
    if(a[0] != b[0] or a.back() != b.back())return -1;
    int n = a.size();
    int res = 0;
    for(int i = 1; i < n-1; i++)
    {
        if(b[i] != a[i])
        {
            if(b[i-1] == b[i+1])b[i] = a[i], res++;
            else return -1;
        }
    }
    return res;
}

int main()
{
    int t; cin >> t;
    string a, b;
    while(t--)
    {
        cin >> a >> b;
        cout << check(a, b) << endl;
    }
    return 0;
}