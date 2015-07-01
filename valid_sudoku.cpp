#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        return valid_row_or_col(board, true) && valid_row_or_col(board, false) && valid_sector(board);
    }

private:
    bool valid_row_or_col(const std::vector<std::vector<char>>& board, bool line)
    {
        for(size_t i=0; i<board.size(); ++i)
        {
            bool flags[9] = {false};
            for(size_t j=0; j<board[0].size(); ++j)
            {
                char cur=line ? board[i][j] : board[j][i];
                if(cur>='1' && cur<='9')
                {
                    if(!flags[cur-'1'])
                    {
                        flags[cur-'1']=true;
                    }
                    else 
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool valid_sector(const std::vector<std::vector<char>>& board)
    {
        for(size_t i=0; i<7; i+=3)
        {
            for(size_t j=0; j<7; j+=3)
            {
                bool flags[9] = {false};
                for(size_t m=i; m<i+3; ++m)
                {
                    for(size_t n=j; n<j+3; ++n)
                    {
                        char cur=board[m][n];
                        if(cur>='1' && cur<='9')
                        {
                            if(!flags[cur-'1'])
                            {
                                flags[cur-'1']=true;
                            }
                            else 
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    std::vector<std::vector<char>> board { {'.','8','7','6','5','4','3','2','1'},
                                           {'2','.','.','.','.','.','.','.','.'},
                                           {'3','.','.','.','.','.','.','.','.'},
                                           {'4','.','.','.','.','.','.','.','.'},
                                           {'5','.','.','.','.','.','.','.','.'},
                                           {'6','.','.','.','.','.','.','.','.'},
                                           {'7','.','.','.','.','.','.','.','.'},
                                           {'8','.','.','.','.','.','.','.','.'},
                                           {'9','.','.','.','.','.','.','.','.'} };
            
    std::cout<<s.isValidSudoku(board)<<std::endl;
    return 0;
}

