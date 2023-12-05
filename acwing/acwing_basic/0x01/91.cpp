#include <bits/stdc++.h>
using namespace std;

//第一维为n位二进制数，其中第i位为1表示第i个点已经经过了，为0表示未经过
//状态dp[i][j]：二进制数i，其中二进制展开位中为1表示哪些点已经访问过了，j表示现在处于j点，dp值表示此时处于j点的最短路径
int dp[1<<20][20];
int n;
int w[20][20];

int hamilton(int n,int w[20][20]){
    memset(dp,0x3f,sizeof(dp));
    //处于0点的二进制数为1，最短路径值为0
    dp[1][0]=0;
    //[0,n-1]位全为1时，表明所有点都访问了
    for(int i=0;i<(1<<n);++i){
        //现求处于j点上的最短路径值
        for(int j=0;j<n;++j){
            //被经过点的状态为i，经过一个点相对应的二进制数位为1，状态i表示经过了好几个点了
            //现状态i处于j点上，更新k->j的最短路径值
            if(i>>j&1){
                for(int k=0;k<n;++k){
                    if(i>>k&1){//二进制数i的第k位为1，更新k->j的值
                        //并且冲k->j的话，一定没有经过j点，要把j点赋值为0，因为每个点只能经过一次
                        dp[i][j]=min(dp[i][j],dp[i^1<<j][k]+w[k][j]);
                    }
                }
            }
        }
    }
    //[0,n-1]全为1表示经过所有点了，现处于n-1的最短路径值返回即可
    return dp[(1<<n)-1][n-1];
}

int main()
{
   cin.tie(0);
   ios::sync_with_stdio(false);
   cin>>n;
   for(int i=0;i<n;++i){
       for(int j=0;j<n;++j){
           cin>>w[i][j];
       }
   }
   cout<<hamilton(n,w)<<endl;
   return 0;
}