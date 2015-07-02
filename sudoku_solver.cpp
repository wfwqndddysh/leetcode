#include<iostream>
#include<cassert>
#include<vector> 

class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>>& board)
    {
        finished_ = false;
        backtrack(board, 0, 0);
    }

private:
    void backtrack(std::vector<std::vector<char>>& board, int r, int c)
    {
        if(finished_)
        {
            return;
        }
        else
        {
            int cur_i=-1;
            int cur_j=-1;
            find_next_position(board, r, c, cur_i, cur_j);

            if(cur_i==-1)
            {
                finished_ = true;
                return;
            }

            std::vector<int> candidates;
            construct_candidates(board, cur_i, cur_j, candidates);

            for(size_t m=0; m<candidates.size(); ++m)
            {
                board[cur_i][cur_j]=candidates[m]+'0';

                backtrack(board, cur_i+cur_j/8, (cur_j+1)%9);
                if(finished_) return;

                board[cur_i][cur_j]='.';
            }
        }
    }

    void find_next_position(const std::vector<std::vector<char>>& board
            , int cur_i, int cur_j
            , int& r, int& c)
    {
        for(size_t j=cur_j; cur_i<9 && j<9; ++j)
        {
            if(board[cur_i][j]=='.')
            {
                r=cur_i;
                c=j;
                return;
            }
        }

        for(size_t i=cur_i; i<9; ++i)
        {
            for(size_t j=0; j<9; ++j)
            {
                if(board[i][j]=='.')
                {
                    r=i;
                    c=j;
                    return;
                }
            }
        }

        return;
    }

    void construct_candidates(const std::vector<std::vector<char>>& board
            , int r, int c
            , std::vector<int>& candidates)
    {
        bool flags[9]={false};

        for(size_t j=0; j<9; ++j)
        {
            if(board[r][j]!='.')
                flags[board[r][j]-'1']=true;
        }

        for(size_t i=0; i<9; ++i)
        {
            if(board[i][c]!='.')
                flags[board[i][c]-'1']=true;
        }

        r=(r/3)*3;
        c=(c/3)*3;
        for(int i=r; i<r+3; ++i)
        {
            for(int j=c; j<c+3; ++j)
            {
                if(board[i][c]!='.')
                    flags[board[i][c]-'1']=true;
            }
        }

        for(int i=0; i<9; ++i)
        {
            if(!flags[i])
                candidates.push_back(i+1);
        }
    }

private:
    bool finished_;
};

int main()
{
    Solution s;

    std::vector<std::vector<char>> board { {'.','.','9','7','4','8','.','.','.'},
                                           {'7','.','.','.','.','.','.','.','.'},
                                           {'.','2','.','1','.','9','.','.','.'},
                                           {'.','.','7','.','.','.','2','4','.'},
                                           {'.','6','4','.','1','.','5','9','.'},
                                           {'.','9','8','.','.','.','3','.','.'},
                                           {'.','.','.','8','.','3','.','2','.'},
                                           {'.','.','.','.','.','.','.','.','6'},
                                           {'.','.','.','2','7','5','9','.','.'} };

    //["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]

    s.solveSudoku(board);

    for(const auto& v : board)
    {
        for(char c : v)
            std::cout<<c<<" ";
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

