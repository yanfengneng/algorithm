#include <bits/stdc++.h>
using namespace std;

struct Node{
  int x1,y1,x2,y2;  
};

// ������[a,b]��[c,d]֮��Ľ�������
int get(int a,int b,int c,int d)
{
    return max(0,min(b,d)-max(a,c));
}
int main()
{
    Node q[3];
    for(int i=0;i<3;++i)cin>>q[i].x1>>q[i].y1>>q[i].x2>>q[i].y2;
    
    // ������ε������
    int res=(q[0].x2-q[0].x1)*(q[0].y2-q[0].y1)+(q[1].x2-q[1].x1)*(q[1].y2-q[1].y1);
    
    // ��ȥ����1�����3���غϲ��֡�����2�����3���غϲ���
    for(int i=0;i<2;++i){
        res-=get(q[i].x1,q[i].x2,q[2].x1,q[2].x2)*get(q[i].y1,q[i].y2,q[2].y1,q[2].y2);
    }
    
    cout<<res<<endl;
    return 0;
}