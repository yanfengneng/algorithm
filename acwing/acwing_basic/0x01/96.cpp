#include <iostream>
#include <cstring>
using namespace std;

int d[15],f[15];

int main()
{
    // d[n]��ʾn��3���µ����ٲ���
    // d[n]=2*d[n-1]=1 ��ʾǰn-1�������ȴ�A���Ƶ�B����Ȼ���n�����Ӵ�A���ƶ���C��������ǰn-1�����Ӵ�B���ƶ���C��
    d[1]=1;
    for(int i=2;i<=12;++i){
        d[i]=2*d[i-1]+1;
    }

    // f[n]��ʾn��4�������ٲ���
    memset(f,0x3f,sizeof f);
    f[0]=0;// 0�����Ӳ���Ҫ���κβ���
    for(int i=1;i<=12;++i){
        for(int j=0;j<i;++j){
            // �Ȱ�j��������4��ģʽ���ƶ���B����Ȼ���i-j��������3��ģʽ���ƶ���D��������ٰ�j�������ƶ���D��
            f[i]=min(f[i],f[j]*2+d[i-j]);
        }
    }
    for(int i=1;i<=12;++i)cout<<f[i]<<endl;
    return 0;
}