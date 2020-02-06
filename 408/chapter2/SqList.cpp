#include <iostream>
using namespace std;

#define maxSize 100
typedef int ElemType;
//˳������͵Ķ���
typedef struct{
    int data[maxSize];//���˳���Ԫ�ص�����
    int length;//˳���ĳ���
}Sqlist;

//0����ʼ��˳���
void initList(Sqlist &L){
    L.length=0;
}

//1���ڵ�i��Ԫ��֮ǰ����Ԫ��ֵe
bool insertElem(Sqlist &L,int i,ElemType e){
    //λ�ò��Ϸ����߱��Ѿ��ﵽ��
    if(i<1||i>L.length+1||L.length>=maxSize)return false;
    //�Ӻ���ǰ��ÿ��Ԫ�����������ƶ�
    for(int j=L.length;j>=i;--j){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

//2��ɾ����i��Ԫ��ֵe
bool deleteElem(Sqlist &L,int i,ElemType &e){
    if(i<1||i>L.length)return false;
    e=L.data[i-1];
    //��i��λ��֮���Ԫ��ǰ�ƣ���i��Ԫ�ص��±�Ϊi-1�����Ϊj-1
    for(int j=i;j<L.length;++j){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

//3��Ѱ��Ԫ��ֵ��λ��
int locateElem(const Sqlist& L,ElemType e){
    for(int i=0;i<L.length;++i){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

//4����ӡ˳����Ԫ��ֵ
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