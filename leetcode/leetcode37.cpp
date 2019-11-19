#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool solved=false;
    //row��ʾÿ�е�10������(0~9),��9�У�col��ʾÿ�е�10�����֣���9�У�box��ʾÿ��С�����10�����֣���9������
    bool row[9][10]={0},col[9][10]={0},box[9][10]={0};
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]=='.')continue;
                int index=3*(i/3)+j/3;//��������012��345��678
                int num=board[i][j]-'0';
                row[i][num]=col[j][num]=box[index][num]=true;
            }
        }
        backtrack(0,0,board);
    }
    
    void backtrack(int i,int j,vector<vector<char>>& board)
    {
        if(solved==true)return;
        if(i>=9){solved=true;return;}
        
        if(board[i][j]!='.')//board[i][j]�ǿգ�������һ��λ��
        {
            if(j<8)
                backtrack(i,j+1,board);
            else if(j==8)
                backtrack(i+1,0,board);
            if(solved==true)
                return;
        }
        else//board[i][j]Ϊ�գ���������
        {
            int index=3*(i/3)+j/3;
            for(int num=1;num<=9;num++)
            {
                if(!row[i][num]&&!col[j][num]&&!box[index][num])//num�Ƿ���Ϲ���
                {
                    board[i][j]=num+'0';//����
                    row[i][num]=col[j][num]=box[index][num]=true;
                    
                    if(j<8)//�ݹ�
                        backtrack(i,j+1,board);
                    else if(j==8)
                        backtrack(i+1,0,board);
                    if(!solved)//����
                    {
                        row[i][num]=col[j][num]=box[index][num]=false; 
                        board[i][j]='.';
                    }
                }
            }
        }
    }
};

int main()
{
    vector<vector<char>> board={
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution().solveSudoku(board);

    for(auto it1:board)
    {
        for(auto it2:it1)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}