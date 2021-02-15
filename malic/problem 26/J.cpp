#include <iostream>
using namespace std;

// m个苹果放入n个盘子的放法
int solve(int m,int n)
{
    // 递归出口：0个苹果只有1种放法；多个苹果只有1个盘子的话，也只有1种放法
    if(m==0||n==1)return 1;
    // 若m<n，最坏情况下m个苹果放入m个盘子，所以n个盘子肯定有空余的，这和m个苹果放入m个盘子是一样的
    if(m<n)return solve(m,m);
    // 若m>=n，分为两种情况。第一种是有空盘子的情况，即m个苹果放在n-1个盘子里面，有一个空盘子；
    // 第二种是没有空盘子，每个盘子至少放一个苹果，那么还多m-n个苹果继续放入n个苹果中
    else return solve(m,n-1)+solve(m-n,n);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        cout<<solve(m,n)<<endl;
    }
    return 0;
}