#include <bits/stdc++.h>
using namespace std;

void insert(int l,int r,int c,vector<int>& b)
{
    b[l]+=c,b[r+1]-=c;
}
int main()
{
    vector<int> a={1,2,3,4,5,6};
    // ��������С�� n+1��������֤��b[n-1+1]�ǲ���Խ�磬�����ڻ�ԭ���������ԭ���� a ʱ���±�ֻ�ñ����� n-1 ����
    // ������� b
    int n=a.size();
    vector<int> b(n+1,0);
    // ���������飬�ڵ�(i,i)�ϲ��� a[i]
    for(int i=0;i<n;++i){
        insert(i,i,a[i],b);
    }
    int l,r,c;
    while(cin>>l>>r>>c){
        insert(l,r,c,b);
    }

    // ��ԭ������飬����������ۼ�֮������� a������a[0]=b[0], a[i]=a[0]+a[1]-a[0]+...+a[i]-a[i-1]=b[0]+b[1]+...+b[i]
    // Ҳ����˵ a[i] ������ b���±�Ϊ����Ԫ�ص� b[0...i] ��ǰ׺�͡�����ֻ���� a[n-1]�������� a[n]��������� a ������±�Ϊ n-1.
    a[0]=b[0];
    for(int i=1;i<n;++i){
        a[i]=a[i-1]+b[i];
    }
    
    for(int i=0;i<n;++i)cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}