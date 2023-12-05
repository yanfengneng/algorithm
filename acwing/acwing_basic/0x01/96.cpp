#include <iostream>
#include <cstring>
using namespace std;

int d[15],f[15];

int main()
{
    // d[n]表示n盘3塔下的最少步数
    // d[n]=2*d[n-1]=1 表示前n-1个盘子先从A柱移到B柱，然后第n个盘子从A柱移动到C柱，最后把前n-1个盘子从B柱移动到C柱
    d[1]=1;
    for(int i=2;i<=12;++i){
        d[i]=2*d[i-1]+1;
    }

    // f[n]表示n盘4塔的最少步数
    memset(f,0x3f,sizeof f);
    f[0]=0;// 0个盘子不需要做任何操作
    for(int i=1;i<=12;++i){
        for(int j=0;j<i;++j){
            // 先把j个盘子在4塔模式下移动到B柱，然后把i-j个盘子在3塔模式下移动到D柱，最后再把j个盘子移动到D柱
            f[i]=min(f[i],f[j]*2+d[i-j]);
        }
    }
    for(int i=1;i<=12;++i)cout<<f[i]<<endl;
    return 0;
}