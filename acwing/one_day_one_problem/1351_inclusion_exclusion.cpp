#include <bits/stdc++.h>
using namespace std;

int n;
int a[3],b[3];

int single()
{
    int res=1;
    // n���ڵ���5�Ļ���ÿһλֻ��5��ѡ����nС��5�Ļ���ÿһλֻ��n��ѡ����
    for(int i=0;i<3;++i)
        res*=min(5,n);
}

int both()
{
    if(n<=5)return n*n*n;
    int res=1;
    for(int i=0;i<3;++i){
        int d=abs(a[i]-b[i]);
        // ����Ϊd��������ѡ��Ϊ5-d��������Ϊ5-d��������Ϊ5-(n-d)����ֻ��һ������
        res*=max(0,5-d)+max(0,5-(n-d));
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;++i)scanf("%d",&a[i]);
    for(int i=0;i<3;++i)scanf("%d",&b[i]);

    cout<<single()*2-both()<<endl;
    return 0;
}