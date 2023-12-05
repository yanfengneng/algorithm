#include <iostream>
using namespace std;

class MyList
{
private:
    struct ListNode
    {
        int val;
        ListNode *next,*prev;
        ListNode(int x):val(x),next(nullptr),prev(nullptr){}
    };
private:
    //ͷ�ڵ�β�ڵ㶼Ϊ�գ���ʾΪ������
    ListNode *head,*tail;
    int size=0;
public:
    MyList():size(0),head(nullptr),tail(nullptr){}

    //1���������Ϊindex�Ľڵ�ֵ
    int get(int index){
        int i=0;
        ListNode *p=head;
        while(p&&i<index){
            p=p->next;
            i++;
        }
        if(p)return p->val;
        else return -1;
    }

    //2����ͷ������ֵΪval���½ڵ�
    void addAtHead(int val){
        if(head!=nullptr){
            ListNode *node=new ListNode(val);
            node->next=head;
            head->prev=node;
            head=node;
        }
        else{
            head=new ListNode(val);
            tail=head;
        }
        ++size;
    }

    //3����β������ֵΪval���½ڵ�
    void addAtTail(int val){
        if(tail!=nullptr){
            ListNode *node=new ListNode(val);
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
        else{//β�ڵ�Ϊ�գ���ôͷ�ڵ�ҲΪ�գ�Ȼ����β�ڵ㶼Ϊ�½ڵ�
            tail=new ListNode(val);
            head=tail;
        }
        ++size;
    }

    //4����index֮ǰ���ֵΪval���½ڵ�
    void addAtIndex(int index,int val){
        //�����ų��������������index��Ȼ��ʣ������index�϶���������
        if(index<=0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        if(index>size)return;
        ListNode *p=nullptr,*cur=head;
        int i=0;
        while(cur&&i<index){
            p=cur;
            cur=cur->next;
            i++;
        }
        ListNode *node=new ListNode(val);
        //����ǰ���Ѿ������������index�ų��ˣ����ڵ�p��cur����Ч������������
        p->next=node;
        node->prev=p;
        node->next=cur;
        cur->prev=node;
        size++;
    }

    //5��ɾ������Ϊindex�Ľڵ�
    void deleteAtIndex(int index){
        //����Ϊ��ʱ������ɾ��
        if(!head)return;
        if(index==0)
        {
            ListNode *del=head;
            head=head->next;
            if(head){//������2�����Ͻڵ�
                head->prev=nullptr;
            }
            else{//����ֻ��һ���ڵ㣬��β���ƿ�
                tail=nullptr;
            }
            delete del;
            size--;
            return;
        }
        //indexΪ���Ϊβ�ڵ㣬������Ҫɾ��β�ڵ�
        if(index==size-1){
            ListNode *del=tail;
            tail=tail->prev;
            //ע�����ﲻ�ô���tailΪ�գ���ΪtailΪ�յĻ�����ô����ֻ�е����ڵ�
            //Ȼ�������ڵ�ֻ��ɾ��0�Žڵ㣬ֻ��indexΪ0ʱ����ɾ����ǰ���Ѿ��������indexΪ0������ˣ��������ﲻ�ڴ���
            if(tail){
                tail->next=nullptr;
            }
            delete del;
            size--;
            return;
        }
        int i=0;
        ListNode *p=nullptr,*cur=head;
        while(cur){
            if(i==index){
                ListNode *del=cur;
                p->next=cur->next;
                if(cur->next){
                    cur->next->prev=p;
                }
                delete del;
                size--;
                return;
            }
            p=cur;
            cur=cur->next;
            ++i;
        }
    }

    //6���������ĳ���
    int length(){
        return size;
    }

    //7���������
    void clear(){
        for(int i=size-1;i>=0;--i){
            deleteAtIndex(i);
        }
    }
};

int main()
{
    MyList ml;
    ml.addAtHead(1);
    ml.addAtTail(3);
    ml.addAtHead(4);
    ml.addAtHead(5);
    ml.addAtIndex(1,2);
    for(int i=0;i<ml.length();++i){
        cout<<ml.get(i)<<" ";
    }
    cout<<endl;
    ml.deleteAtIndex(1);
    for(int i=0;i<ml.length();++i){
        cout<<ml.get(i)<<" ";
    }
    cout<<endl;
    ml.clear();
    cout<<ml.length()<<endl;
    system("pause");
}