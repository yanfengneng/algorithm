#include <iostream>
using namespace std;

//շת����������Լ��
int gcd(int a,int b){
    if(!a||!b)return 0;
    while(b){//����Ϊ0��ʾ�����Ѿ��ҵ����Լ����
        //ÿ��������������������������֮��aΪ������bΪ������ֱ��bΪ0Ϊֹ
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

//���Լ��������֮���������������Լ��
int lcm(int a,int b){
    if(!a||!b)return 0;
    return a*b/gcd(a,b);
}

int main()
{
    cout<<gcd(319,377)<<endl;
    cout<<lcm(319,377)<<endl;
    system("pause");
}