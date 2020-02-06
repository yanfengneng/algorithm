#include <iostream>
using namespace std;

#define maxSize 100
typedef int ElemType;
//顺序表类型的定义
typedef struct{
    int data[maxSize];//存放顺序表元素的数组
    int length;//顺序表的长度
}Sqlist;

//0、初始化顺序表
void initList(Sqlist &L){
    L.length=0;
}

//1、在第i个元素之前插入元素值e
bool insertElem(Sqlist &L,int i,ElemType e){
    //位置不合法或者表长已经达到了
    if(i<1||i>L.length+1||L.length>=maxSize)return false;
    //从后至前，每个元素依次向右移动
    for(int j=L.length;j>=i;--j){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

//2、删除第i个元素值e
bool deleteElem(Sqlist &L,int i,ElemType &e){
    if(i<1||i>L.length)return false;
    e=L.data[i-1];
    //第i个位置之后的元素前移，第i个元素的下表为i-1，起初为j-1
    for(int j=i;j<L.length;++j){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

//3、寻找元素值的位置
int locateElem(const Sqlist& L,ElemType e){
    for(int i=0;i<L.length;++i){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

//4、打印顺序表的元素值
void printList(Sqlist& L){
    for(int i=0;i<L.length;++i){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Sqlist L;
    initList(L);
    for(int i=0;i<10;i++){
        insertElem(L,i,i*2);
    }
    printList(L);
    ElemType e=-1;
    deleteElem(L,1,e);
    cout<<e<<endl;
    deleteElem(L,1,e);
    cout<<e<<endl;
    cout<<locateElem(L,6)<<endl;
    printList(L);
    system("pause");
}