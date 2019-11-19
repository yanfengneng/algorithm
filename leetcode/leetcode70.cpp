 #include <iostream>
 using namespace std;
 
 int climbStairs(int n){
        int memo[n+1]={0};
        return helper(0,n,memo);
    }
    int helper(int i,int n,int* memo){
        if(i>n)return 0;
        if(i==n)return 1;
        if(memo[i]>0)return memo[i];
        memo[i]=helper(i+1,n,memo)+helper(i+2,n,memo);
        return memo[i];
    }