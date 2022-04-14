#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solveNQueens(int n);
void backtrack(int row, vector<string> &board, vector<vector<string>> &result);
bool isVaild(vector<string> &board, int row, int col);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    auto res=solveNQueens(n);
    for (auto r : res)
        {
            for (auto str : r)cout << str << endl;
            cout<<endl;
        }
    return 0;
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.')); //��������
    vector<vector<string>> result;           //���е�n�ʺ�
    backtrack(0, board, result);             //���л���
    return result;
}

void backtrack(int row, vector<string> &board, vector<vector<string>> &result)
{
    if (row == board.size())
        result.push_back(board);
    else
    {
        for (int col = 0; col < board.size(); col++) //ÿһ�ж���һ��ѡ��
        {
            //���ѡ������λ�ûᱻ������������
            if (!isVaild(board, row, col))
                continue;

            /*choose����*/
            //ע�������ѡ���б��С�ˣ���ΪҪ������һ��ѡ�ʺ�
            //ͬʱ����ľ���·��Ҳ�����˾��ߣ�Ҳ�����������Ϊ�ʺ���
            board[row][col] = 'Q';

            /*������һ�е�ѡ��*/
            backtrack(row + 1, board, result);

            /*unchoose����*/
            //�����ѡ���Ƴ�����·���ˣ�Ҳ���ǰ�����ʺ�ԭ�ɵ�
            //��Ȼ���ѡ��Ҳ���¼���ѡ���б��ˣ�ע�����ѡ���б�Ϊ��
            board[row][col] = '.';
        }
    }
}

//�ж�board[row][col]�Ƿ���Է���Q
bool isVaild(vector<string> &board, int row, int col)
{
    //������Ϸ�
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 'Q')
            return false;

    //�����б�Ϸ�
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
        if (board[i][j] == 'Q')
            return false;

    //�����б�Ϸ�
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    //���ü���·�����Ϊ�·���û���ûʺ�
    return true;
}