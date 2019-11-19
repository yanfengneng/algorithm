#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.')); //建立棋盘
        vector<vector<string>> result;//可行的n皇后
        backtrack(0,board,result);//进行回溯
        return result;
    }
    
    void backtrack(int row,vector<string>& board,vector<vector<string>>& result)
    {
        if(row==board.size())
            result.push_back(board);
        else{
            for(int col=0;col<board.size();col++)//每一列都是一个选择
            {
                //如果选择的这个位置会被攻击，则跳过
                if(!isVaild(board,row,col))continue;
                
                /*choose过程*/
                //注意这里的选择列表变小了，因为要进入下一行选皇后
                //同时这里的决策路径也做出了决策，也就是这个点作为皇后了
                board[row][col]='Q';
                
                /*进行下一行的选择*/
                backtrack(row+1,board,result);
                
                /*unchoose过程*/
                //把这个选择移除决策路径了，也就是把这个皇后还原成点
                //当然这个选择也重新加入选择列表了，注意这个选择列表为列
                board[row][col]='.';
            }
        }
    }
    
    //判断board[row][col]是否可以放置Q
    bool isVaild(vector<string>& board,int row,int col)
    {
        //检查正上方
        for(int i=0;i<row;++i)
            if(board[i][col]=='Q')return false;
        
        //检查右斜上方
        for(int i=row-1,j=col+1;i>=0&&j<board.size();i--,j++)
            if(board[i][j]=='Q')return false;
        
        //检查左斜上方
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
            if(board[i][j]=='Q')return false;
        
        //不用检查下方，因为下方还没放置皇后
        return true;
    }
};

int main()
{
    vector<vector<string>> board=Solution().solveNQueens(4);
    for(const auto& v1:board)//遍历出每一个棋盘
    {
        for(const auto v2:v1)//每一个棋盘，遍历出每一行
            cout<<v2<<endl;
        cout<<endl;     
    }
    system("pause");
}