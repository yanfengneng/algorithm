#include <iostream>
#include <cstring>
using namespace std;

char* Delete(char* s)
{
	char* p = s;
	char* r = s;//用来记录s的起始地址
	while (*s != '\0')
	{
		if (*s != ' ')//当s所指向的字符不为空时，用s所指向的字符覆盖p所指向的字符
		{
			*p = *s;
			p++;
		}
		s++;
	}
	*p = '\0';//封闭字符串，s中的空格已被消除
	return r;//返回字符串起始地址
}
int main()
{
	char s[] = "Are you ok?";
	cout << Delete(s) << endl;
	system("pause");
}