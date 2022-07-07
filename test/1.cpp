#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a='a',B='B';
    // 小大小写互换：把二进制数组第5位，由0变1 或 由1变0
    cout<<char(a^32)<<"---"<<char(B^32)<<endl;
    // 字母转换为小写：把二进制数的第5位变为1
    cout<<char(a|32)<<"---"<<char(B|32)<<endl;
    // 字母转换为大写：把二进制数的第5位变为0
    cout<<char(a&-33)<<"---"<<char(B&-33)<<endl;
    return 0;
}