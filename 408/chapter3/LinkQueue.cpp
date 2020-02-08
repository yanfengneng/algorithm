#include <iostream>
using namespace std;

typedef int QElemType;
//�����нڵ�
typedef struct QNode
{
    QElemType data;
    QNode *next;
}QNode,*QueuePtr;

//������
typedef struct
{
    QueuePtr front,rear;//��ͷָ�롢��βָ��
}LinkQueue;

//�����
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

//�Ƴ���ͷԪ��
bool deQueue(LinkQueue& Q,QElemType& e){
    if(Q.rear==nullptr)return false;
    QNode *del=Q.front;
    if(Q.rear==Q.front){//������ֻ��һ��Ԫ��ʱ
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