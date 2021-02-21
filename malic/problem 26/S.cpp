#include <bits/stdc++.h>
/*---------------------------------------*/
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
/*---------------------------------------*/
void helper(vector<vector<int>> &vec,vector<int> &tmp) {
    int a=tmp.at(0),b=tmp.at(1),c=tmp.at(2),d=tmp.at(3),e=tmp.at(4),f=tmp.at(5);
    vec.push_back({a,b,c,d,e,f});
    vec.push_back({a,b,f,e,c,d});
    vec.push_back({a,b,d,c,f,e});
    vec.push_back({a,b,e,f,d,c});

    vec.push_back({b,a,d,c,e,f});
    vec.push_back({b,a,f,e,d,c});
    vec.push_back({b,a,c,d,f,e});
    vec.push_back({b,a,e,f,a,d});

    vec.push_back({c,d,b,a,e,f});
    vec.push_back({c,d,f,e,b,a});
    vec.push_back({c,d,a,b,f,e});
    vec.push_back({c,d,e,f,a,b});

    vec.push_back({d,c,a,b,e,f});
    vec.push_back({d,c,f,e,a,b});
    vec.push_back({d,c,b,a,f,e});
    vec.push_back({d,c,e,f,b,a});

    vec.push_back({e,f,c,d,b,a});
    vec.push_back({e,f,a,b,c,d});
    vec.push_back({e,f,d,c,a,b});
    vec.push_back({e,f,b,a,d,c});

    vec.push_back({f,e,c,d,a,b});
    vec.push_back({f,e,b,a,c,d});
    vec.push_back({f,e,d,c,b,a});
    vec.push_back({f,e,a,b,d,c});
}

bool check(vector<vector<int>> &vec,vector<int> &tmp) {
    for (vector<int> &i:vec) {
        if (i==tmp) {
            return true;
        }
    }
    return false;
}

int main()
{
   
}