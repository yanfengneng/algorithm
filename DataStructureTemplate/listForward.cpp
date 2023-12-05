#include <iostream>
using namespace std;

class MyListForward
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){}
    };
    ListNode* head;
public:
    MyListForward():head(nullptr){}

    //1����������е�index���ڵ��ֵ
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

    //2��������ͷ����һ��ֵΪval�Ľڵ�
    void addAtHead(int val){
        ListNode *p=new ListNode(val);
        p->next=head;
        head=p;//����ͷ�ڵ�
    }

    //3��������β�����һ��ֵΪval�Ľڵ�
    void addAtTail(int val){
        ListNode *p=new ListNode(val);
        //����Ϊ�գ�ֱ�ӽ��½ڵ���Ϊͷ�ڵ�
        if(head==nullptr){
            head=p;
            return;
        }
        ListNode *q=head;
        //����ֱ��q��next�ڵ�Ϊ��
        while(q->next){
            q=q->next;
        }
        q->next=p;
    }

    //4��������Ϊindex�Ľڵ�֮ǰ���ֵΪval�Ľڵ�
    void addAtIndex(int index,int val){
        ListNode *node=new ListNode(val);
        //1��indexС�ڵ���0��ֱ����ͷ������ڵ�
        if(index<=0)
        {//��indexС�ڵ���0�����ǽ���Ҫ��ͷ�ڵ�ǰ������½ڵ������
        //ע�����ﲻ��ʹ��ָ��p����Ϊp=nodeʱ��p��ָ��ĵ�ַ�����˱仯��headָ��ĵ�ַû�б仯��������������Ҫʹ��ָ��head
            node->next=head;
            head=node;
            return;
        }
        int i=0;
        ListNode *p=head;
        //������Ϊindex�Ľڵ�֮ǰ�����½ڵ㣬������Ҫ�ҵ�����ǰ���ڵ㣬Ȼ�����������ǰ���ڵ����
        while(p&&i<index-1)
        {
            p=p->next;
            ++i;
        }
        //2��pΪ�����ڵ��ǰ���ڵ�
        if(p)
        {
            node->next=p->next;
            p->next=node;
        }
    }

    //5��ɾ������Ϊindex�Ľڵ�
    void deleteAtIndex(int index){
        //1��indexΪ0������ֱ��ɾ��head�ڵ�
        if(index==0&&head!=nullptr)
        {
            ListNode *del=head;
            head=head->next;
            delete del;
            return;
        }
        int i=0;
        ListNode* p=head;
        //ɾ������Ϊindex�Ľڵ㣬������Ҫ�ҵ�����ǰ���ڵ�p��p->nextΪ��Ҫɾ���ڵ�
        while(p&&i<index-1)
        {
            p=p->next;
            i++;
        }
        //2��index��������Χ��ɾ��ʧ��
        if(!p)return;
        //3��index��λ�úϷ��������ҵ���Ҫɾ����p->next�ڵ�
        if(p->next)
        {
            ListNode *del=p->next;
            p->next=del->next;
            delete del;
        }
    }

    //6��������
    int length(){
        int i=0;
        ListNode *p=head;
        while(p){
            i++;
            p=p->next;
        }
        return i;
    }

    //7���������
    void clear(){
        ListNode *del=nullptr;
        while(head){
            del=head;
            head=head->next;
            delete del;
        }
    }
};

int main()
{
    MyListForward mlf;
    mlf.addAtIndex(0,10);
    mlf.addAtIndex(0,20);
    mlf.addAtIndex(1,30);
    for(int i=0;i<mlf.length();++i){
        cout<<mlf.get(i)<<" ";
    }
    cout<<endl;
    mlf.clear();
    cout<<mlf.length()<<endl;
    system("pause");
}