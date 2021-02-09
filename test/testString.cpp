#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = " hello world ";
	s.insert(2, s, 1, 2);
	cout << s << endl;
	s.insert(s.begin()+3, s.begin(), s.end());
	cout << s << endl;
	s.append(s);
	cout << s << endl;
	s.append(s.begin() + 1, s.end() - 1);
	for (auto begin = s.begin(); begin != s.end(); begin++)
		cout << *begin << " ";
	cout << endl;
	s.assign(s);
	cout << s << endl;
	s.assign(s.begin() + 1, s.end() - 1);
	cout << s << endl;
	return 0;
}