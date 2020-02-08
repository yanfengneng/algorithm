#include <iostream>
using namespace std;

typedef int QElemType;
//链队列节点
typedef struct QNode
{
    QElemType data;
    QNode *next;
}QNode,*QueuePtr;

//链队列
typedef struct
{
    QueuePtr front,rear;//队头指针、队尾指针
}LinkQueue;

//入队列
bool enQueue(LinkQueue& Q,QElemType e){
    QueuePtr node=(QueuePtr)malloc(sizeof(QNode));
    if(!node)return false;
    node->data=e;
    node->next=nullptr;
    if(Q.rear==nullptr){
        Q.front=Q.rear=node;
    }
    else{
        Q.rear->next=node;
        Q.rear=node;
    }
    return true;
}

//移除队头元素
bool deQueue(LinkQueue& Q,QElemType& e){
    if(Q.rear==nullptr)return false;
    QNode *del=Q.front;
    if(Q.rear==Q.front){//队列中只有一个元素时
        Q.front=Q.rear=nullptr;
    }
    else{
        Q.front=Q.front->next;
    }
    e=del->data;
    free(del);
    return true;
}

void initQueue(LinkQueue& Q){
    Q.rear=Q.front=nullptr;
}

int main()
{
    LinkQueue Q;
    initQueue(Q);
    for(int i=0;i<10;++i){
        enQueue(Q,i);
    }
    QElemType e;
    for(int i=0;i<10;++i){
        deQueue(Q,e);
        cout<<e<<" ";
    }
    cout<<endl;
}