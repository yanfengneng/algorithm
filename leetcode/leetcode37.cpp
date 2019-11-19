#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool solved=false;
    //row表示每行的10个数字(0~9),共9行；col表示每列的10个数字，共9列；box表示每个小方块的10个数字，共9个方块
    bool row[9][10]={0},col[9][10]={0},box[9][10]={0};
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]=='.')continue;
                int index=3*(i/3)+j/3;//方块索引012，345，678
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
        
        if(board[i][j]!='.')//board[i][j]非空，考虑下一个位置
        {
            if(j<8)
                backtrack(i,j+1,board);
            else if(j==8)
                backtrack(i+1,0,board);
            if(solved==true)
                return;
        }
        else//board[i][j]为空，可以填数
        {
            int index=3*(i/3)+j/3;
            for(int num=1;num<=9;num++)
            {
                if(!row[i][num]&&!col[j][num]&&!box[index][num])//num是否符合规则
                {
                    board[i][j]=num+'0';//填数
                    row[i][num]=col[j][num]=box[index][num]=true;
                    
                    if(j<8)//递归
                        backtrack(i,j+1,board);
                    else if(j==8)
                        backtrack(i+1,0,board);
                    if(!solved)//回溯
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