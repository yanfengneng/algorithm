#include <iostream>
#include <cstring>
using namespace std;

void testArray(int* d,int m,int n)
{
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cout<<*(d+i*n+j)<<" ";
        }
        cout<<endl;
    }    
}

void testArray_1(int** d,int m,int n)
{
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cout<<*((int*)d+i*n+j)<<" ";
        }
        cout<<endl;
    }    
}

int main()
{
    int dp[3][2]={{1,4},{3,4},{5,6}};
    testArray(*dp,3,2);
    return 0;
}