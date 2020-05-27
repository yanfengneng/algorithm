#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef char TElemType;
typedef struct BiTNode 
{
	TElemType data;
	struct BiTNode* Ichild, * rchild;
}BiTNode,*BiTree;
int CreateBiTree(BiTree& T);
int PreOrderTraverse(BiTree T);
int InOrderTraverse(BiTree T);
int PostOrderTraverse(BiTree T);
int LevelOrderTraverse(BiTree T);

int main()
{
	BiTree T;
	CreateBiTree(T);
	cout<<"Preorder Traverse:";
	PreOrderTraverse(T);
	cout<<endl;
	cout<<"InOrder Traverse:";
	InOrderTraverse(T);
	cout<<endl;
	cout<<"PostOrder Traverse:";
	PostOrderTraverse(T);
	cout<<endl;
	cout<<"LevelOrder Traverse:";
	LevelOrderTraverse(T);
	cout<<endl;
	system("pause");
	return 0;
}
/*
ABD##FE###CG#H##I##
*/
int CreateBiTree(BiTree& T)
{
	TElemType e;
	cin >> e;
	if (e == '#')//#��ʾ����
		T = NULL;
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T)
			exit(0);
		else
		{
			T->data = e;//���ɸ��ڵ�
			CreateBiTree(T->Ichild);//����������
			CreateBiTree(T->rchild);//����������
		}
	}
	return 1;
}

int PreOrderTraverse(BiTree T)//ǰ�����
{
	stack<BiTree> s;
	BiTree p = T;//���ڵ�
	while (p != NULL || !s.empty())
	{
		while (p != NULL)//������
		{
			cout << p->data;
			s.push(p);
			p = p->Ichild;
		}
		if (!s.empty())
		{
			p = s.top();//�õ����ڵ�
			s.pop();//���ڵ��ջ
			p = p->rchild;//
		}
	}
	cout<<endl;
	return 0;
}

int InOrderTraverse(BiTree T)//�������
{
	stack<BiTree> s;
	BiTree p = T;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->Ichild;
		}
		if (!s.empty())
		{
			p = s.top();//�õ���׶˵���ڵ�
			cout << p->data;//����ڵ�ֵ
			s.pop();
			p = p->rchild;
		}
	}
	cout<<endl;
	return 0;
}

int PostOrderTraverse(BiTree T)//�������
{
	stack<BiTree> s;
	BiTree cur;//��ǰ���
	BiTree pre = NULL;//ǰһ�η��ʵĽ��
	s.push(T);//���ڵ��ջ
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->Ichild == NULL && cur->rchild == NULL) ||
			(pre != NULL && (pre == cur->Ichild || pre == cur->rchild)))
		{
			cout << cur->data;//��ǰ���û�к��ӽڵ���ӽڵ㶼�Ѿ���������
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->rchild != NULL)
				s.push(cur->rchild);//�Һ����Ƚ�ջ
			if (cur->Ichild != NULL)
				s.push(cur->Ichild);//���Ӻ��ջ����֤��ȡջ��Ԫ��ʱ���������Һ���֮ǰ������
		}
	}
	cout<<endl;
	return 0;
}

int LevelOrderTraverse(BiTree T)//�������
{
	if (T == NULL)
		return 0;
	queue<BiTree> Q;
	Q.push(T);//�Ѹ��������
	while (!Q.empty())//ѭ������֮���ٴ��жϣ�ֱ������Ϊ��
	{
		cout << Q.front()->data;
		if (Q.front()->Ichild!= NULL)//��ڵ������
			Q.push(Q.front()->Ichild);
		if (Q.front()->rchild != NULL)//�ҽڵ������
			Q.push(Q.front()->rchild);
		Q.pop();//��ͷ����
	}
	cout << endl;
	return 1;
}