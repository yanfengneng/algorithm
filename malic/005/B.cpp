#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using LL = long long;
double a[N];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            double x=a[i]*a[j];
            if(x==LL(x))cnt++;
        }
    }
    cout<<cnt<<endl;
}