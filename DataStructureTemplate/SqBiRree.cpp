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
	if (e == '#')//#表示空树
		T = NULL;
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T)
			exit(0);
		else
		{
			T->data = e;//生成根节点
			CreateBiTree(T->Ichild);//构造左子树
			CreateBiTree(T->rchild);//构造右子树
		}
	}
	return 1;
}

int PreOrderTraverse(BiTree T)//前序遍历
{
	stack<BiTree> s;
	BiTree p = T;//根节点
	while (p != NULL || !s.empty())
	{
		while (p != NULL)//根左右
		{
			cout << p->data;
			s.push(p);
			p = p->Ichild;
		}
		if (!s.empty())
		{
			p = s.top();//得到根节点
			s.pop();//根节点出栈
			p = p->rchild;//
		}
	}
	cout<<endl;
	return 0;
}

int InOrderTraverse(BiTree T)//中序遍历
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
			p = s.top();//得到最底端的左节点
			cout << p->data;//输出节点值
			s.pop();
			p = p->rchild;
		}
	}
	cout<<endl;
	return 0;
}

int PostOrderTraverse(BiTree T)//后序遍历
{
	stack<BiTree> s;
	BiTree cur;//当前结点
	BiTree pre = NULL;//前一次访问的结点
	s.push(T);//根节点出栈
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->Ichild == NULL && cur->rchild == NULL) ||
			(pre != NULL && (pre == cur->Ichild || pre == cur->rchild)))
		{
			cout << cur->data;//当前结点没有孩子节点或孩子节点都已经被访问了
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->rchild != NULL)
				s.push(cur->rchild);//右孩子先进栈
			if (cur->Ichild != NULL)
				s.push(cur->Ichild);//左孩子后进栈，保证在取栈顶元素时，左孩子在右孩子之前被访问
		}
	}
	cout<<endl;
	return 0;
}

int LevelOrderTraverse(BiTree T)//层序遍历
{
	if (T == NULL)
		return 0;
	queue<BiTree> Q;
	Q.push(T);//把根结点推入
	while (!Q.empty())//循环结束之后再次判断，直到队列为空
	{
		cout << Q.front()->data;
		if (Q.front()->Ichild!= NULL)//左节点进队列
			Q.push(Q.front()->Ichild);
		if (Q.front()->rchild != NULL)//右节点进队列
			Q.push(Q.front()->rchild);
		Q.pop();//队头出列
	}
	cout << endl;
	return 1;
}