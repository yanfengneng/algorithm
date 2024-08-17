#include <iostream>
using namespace std;

#define MaxSize 1000
typedef int QElemType;

//由于顺序队列队头元素出队列之后，队前面的空间会被浪费，所以我们将顺序队列改为循环队列
//循环队列实现
typedef struct
{
    int data[MaxSize];
    int front,rear;
}SqQueue;

void initQueue(SqQueue& Q){
    Q.front=Q.rear=0;
}

int length(SqQueue Q){
    return (Q.rear-Q.front+MaxSize)%MaxSize;
}

//进队列
bool enQueue(SqQueue& Q,QElemType e){
    if((Q.rear+1)%MaxSize==Q.front)return false;
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}

//移除队头元素
bool deQueue(SqQueue& Q,QElemType& e){
    //判断队列是否为空
    if(Q.front==Q.rear)return false;
    e=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}

int main()
{
    SqQueue Q;
    initQueue(Q);
    for(int i=0;i<10;++i){
        enQueue(Q,i);
    }
    cout<<length(Q)<<endl;
    QElemType e;
    while(length(Q)){
        deQueue(Q,e);
        cout<<e<<" ";
    }
    cout<<endl;
}