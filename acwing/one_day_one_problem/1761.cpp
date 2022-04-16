#include <bits/stdc++.h>
using namespace std;

struct Node{
  int x1,y1,x2,y2;  
};

// 求区间[a,b]与[c,d]之间的交集长度
int get(int a,int b,int c,int d)
{
    return max(0,min(b,d)-max(a,c));
}
int main()
{
    Node q[3];
    for(int i=0;i<3;++i)cin>>q[i].x1>>q[i].y1>>q[i].x2>>q[i].y2;
    
    // 两块矩形的总面积
    int res=(q[0].x2-q[0].x1)*(q[0].y2-q[0].y1)+(q[1].x2-q[1].x1)*(q[1].y2-q[1].y1);
    
    // 减去矩形1与矩形3的重合部分、矩形2与矩形3的重合部分
    for(int i=0;i<2;++i){
        res-=get(q[i].x1,q[i].x2,q[2].x1,q[2].x2)*get(q[i].y1,q[i].y2,q[2].y1,q[2].y2);
    }
    
    cout<<res<<endl;
    return 0;
}