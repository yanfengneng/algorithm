#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

class Trie {
private:
	bool is_string;
	Trie* next[26];
	string str;
public:
	Trie() {
		is_string = false;
		str = "";
		memset(next, 0, sizeof(next));
	}
	void insert(string word)//���뵥�ʣ�����ǰ׺��
	{
		Trie* root = this;
		for (auto w : word)
		{
			if (root->next[w - 'a'] == nullptr)root->next[w - 'a'] = new Trie();
			root = root->next[w - 'a'];
		}
		root->str.append(word);
		root->is_string = true;
	}

	void search(vector<string>& result, vector<vector<char>>& board)
	{
		Trie* root = this;
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				helper(result, board, root, i, j);
	}

	void helper(vector<string>& result, vector<vector<char>>& board, Trie* note, int x, int y)
	{
		if (note->is_string == true) {//��board���ҵ�words��һ�����ʣ���ӵ�result��
			note->is_string = false;//���õ��ʱ��Ϊfalse,��ֹ��word���ٴεݹ鵽������ʣ��Ӷ�����ظ����
			result.push_back(note->str);
			return;
		}
		if (x < 0 || x == board.size() || y < 0 || y == board[x].size())return;//�����߽�,���ܼ����ݹ�
		if (board[x][y]=='#'||note->next[board[x][y] - 'a'] == nullptr)return;//����(x,y)��Ӧ���ַ�����ǰ׺���У��ݹ鷽�򲻶ԣ����ص���һ������
		note = note->next[board[x][y] - 'a'];//noteָ����һ���ַ��ڵ�
		char temp = board[x][y];
		board[x][y] = '#';//���(x,y)��Ӧ���ַ��ѱ����ʹ�����ֹͬһ����Ԫ���ڵ��ַ���һ���������ظ�ʹ��
		helper(result, board, note, x + 1, y);
		helper(result, board, note, x - 1, y);
		helper(result, board, note, x, y + 1);
		helper(result, board, note, x, y - 1);
		board[x][y] = temp;
	}
};
class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie* root = new Trie();
		vector<string> result;
		for (auto word : words)
			root->insert(word);
		root->search(result, board);
		return result;
	}
};

int main()
{
	vector<string> words = { "oath","pea","eat","rain" };
	vector<vector<char>> board = { {'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'} };
	vector<string> result = Solution().findWords(board, words);
	for (auto it : result)
		cout << it << " ";
	cout << endl;
	system("pause");
}