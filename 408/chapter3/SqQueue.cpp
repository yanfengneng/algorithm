#include <iostream>
using namespace std;

#define MaxSize 1000
typedef int QElemType;

//����˳����ж�ͷԪ�س�����֮�󣬶�ǰ��Ŀռ�ᱻ�˷ѣ��������ǽ�˳����и�Ϊѭ������
//ѭ������ʵ��
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

//������
bool enQueue(SqQueue& Q,QElemType e){
    if((Q.rear+1)%MaxSize==Q.front)return false;
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}

//�Ƴ���ͷԪ��
bool deQueue(SqQueue& Q,QElemType& e){
    //�ж϶����Ƿ�Ϊ��
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