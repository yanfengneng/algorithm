#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);
typedef pair<double,double> PDD;

double distance(PDD p1,PDD p2)
{
    double diff_x=p1.first-p2.first,diff_y=p1.second-p2.second;
    return sqrt(diff_x*diff_x+diff_y*diff_y);
}

void solve(PDD p1,PDD p2,int n,double angle)
{
    if(n==0)
        printf("%.8f %.8f\n",p1.first,p1.second);
    else
    {
        double len=distance(p1,p2);
        double R=len/3;
        PDD s,t,u;

        // 点 s 的坐标直接由 p1 的坐标和 p1->p2与x抽的角度θ来求
        s.first=p1.first+R*cos(angle);
        s.second=p1.second+R*sin(angle);

        // 中间点 u 的坐标由刚求出来的 s 的坐标来求，以及新的角度θ+60°
        u.first=s.first+R*cos(angle+PI/3);
        u.second=s.second+R*sin(angle+PI/3);

        // 点 t 的坐标直接用 p1的坐标+2R+θ来求
        t.first=p1.first+2*R*cos(angle);
        t.second=p1.second+2*R*sin(angle);

        // 递归处理p1-s、s-u、u-t、t-p2
        // 这里的角度都是与x轴的角度
        solve(p1,s,n-1,angle);
        solve(s,u,n-1,angle+PI/3);
        solve(u,t,n-1,angle-PI/3);
        solve(t,p2,n-1,angle);
    }  
}

int main()
{
    int n;
    cin>>n;

    solve({0,0},{100,0},n,0);

    puts("100.00000000 0.00000000");

    return 0;
}