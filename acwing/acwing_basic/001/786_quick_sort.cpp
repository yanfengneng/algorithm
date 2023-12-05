#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int q[N], n, k;

int quick_sort(int l,int r,int k)
{
	// ������ֻ��һ�����ˣ�����Ϊ��kС����
	if(l==r)return q[l];

	int x=q[l+r>>1],i=l-1,j=r+1;
	while(i<j)
	{
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j)swap(q[i],q[j]);
	}
	// С�ڵ���x�ĸ�����cnt
	int cnt=j-l+1;
	// ��k<=cnt����ô���������Ѱ�ҵ�kС����
	if(k<=cnt)return quick_sort(l,j,k);
	// ��k>cnt����ô�������ұ�Ѱ�ҵ�k-cntС����
	return quick_sort(j+1,r,k-cnt);
}

int main()
{
    scanf("%d %d",&n,&k);
	for (int i = 0; i < n; ++i)scanf("%d",&q[i]);
    cout<<quick_sort(0,n-1,k)<<endl;
	return 0;
}