#include <iostream>
#include <algorithm>
using namespace std;

int n,c;
int a[100000];

bool check(int mid){
    int pre=0,count=1;//pre��ʾ��һͷţ�ŵ�λ�ã�count��������
    for(int i=1;i<n;++i){
        if(a[i]-a[pre]>=mid){
            pre=i;
            count++;
        }
    }
    if(count>=c)return true;
    return false;
}

int main()
{
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int left=0,right=1000000000;
    while(left<right){//���ַ�����С�ڵ���x�����ֵ
        //midΪ�����ͷţ�ľ��룬����Ҫʹd��ֵ����ö���������ʹ������a[i]-a[pre]>=mid
        int mid=left+((right-left+1)>>1);//ȡ����λ����������ѭ��
        if(check(mid))left=mid;
        else right=mid-1;
    }
    printf("%d\n",left);
}
/*
5 3
1
2
8
4
9
*/