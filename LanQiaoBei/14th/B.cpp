#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int a[N][N];
int op[10];

int res = 0;
int cal(int a, int b, int c)
{
    if(c == 1)return a & b;
    else if(c == 2)return a | b;
    return a ^ b;
}

/*思路：总共有需要计算 10 次，每次计算有三种选择，直接枚举 3^10 种情况即可*/
// 使用 dfs 枚举所有情况即可
void dfs(int n)
{
    if(n == 10)// 枚举了 10 次，然后计算 10 次之后的结果
    {
        int c = 0;
        for(int i = 1; i < 5; i++)
            for(int j = 0; j < 5- i; j++)
                a[i][j] = cal(a[i-1][j], a[i-1][j+1], op[c++]);
        if(a[4][0] == 1)res++;
        return;  
    }

    // 每次计算，枚举三种计算方式
    for(int i = 1; i <= 3; i++)
    {
        op[n] = i;
        dfs(n+1);
    }
}
int main()
{
    a[0][0] = a[0][2] = a[0][4] = 1;
    a[0][1] = a[0][3] = 0;
    dfs(0);
    cout << res << endl;
    return 0;
}