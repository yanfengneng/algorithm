#include <iostream>
#include <cstring>
using namespace std;

char* Delete(char* s)
{
	char* p = s;
	char* r = s;//������¼s����ʼ��ַ
	while (*s != '\0')
	{
		if (*s != ' ')//��s��ָ����ַ���Ϊ��ʱ����s��ָ����ַ�����p��ָ����ַ�
		{
			*p = *s;
			p++;
		}
		s++;
	}
	*p = '\0';//����ַ�����s�еĿո��ѱ�����
	return r;//�����ַ�����ʼ��ַ
}
int main()
{
	char s[] = "Are you ok?";
	cout << Delete(s) << endl;
	system("pause");
}