#include <cstdio>
#include <iostream>
using namespace std;

class Data
{
    int x;
    Data(const Data& a);
};

class data
{
    int x;
    data(const data& a);
};
char* q()
{
    static char s[10000];
    char str[] = "char* q()%c{%c    static char s[10000];%c    char str[] = %c%s%c;%c    sprintf(s, str, 10, 10, 10, 34, str, 34, 10, 10, 10, 10);%c    return s;%c}";
    sprintf(s, str, 10, 10, 10, 34, str, 34, 10, 10, 10, 10);
    return s;
}
int main() {
    
    return 0;
}