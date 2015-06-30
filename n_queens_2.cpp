#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int totalNQueens(int n)
    {
        n_=n;
        cnt_ = 0;
        std::vector<std::vector<bool>> flags(n, std::vector<bool>(n, false));

        backtrack(0, flags);
        return cnt_;
    }

private:
    void backtrack(int cur
            , std::vector<std::vector<bool>>& flags)
    {
        if(cur==n_)
        {
            cnt_++;
        }
        else
        {
            std::vector<std::pair<int, int>> candiates;
            size_t sz=construct_candiates(flags, candiates);
            for(size_t i=0; i<sz; ++i)
            {
                std::vector<std::pair<int, int>> sets;
                set_flags(candiates[i].first, candiates[i].second, sets, flags);

                backtrack(cur+1, flags);

                reset_flags(sets, flags);
            }
        }
    }

    size_t construct_candiates(const std::vector<std::vector<bool>>& flags
            , std::vector<std::pair<int, int>>& candiates)
    {
        int i;
        int j;
        if(!find_first_candiate(flags, i, j)) return 0;

        candiates.push_back({i, j});

        for(int r=i, c=j-1; c>=0; --c)
        {
            if(!flags[r][c]) candiates.push_back({r, c});
        }
        for(int r=i, c=j+1; c<n_; ++c)
        {
            if(!flags[r][c]) candiates.push_back({r, c});
        }

        return candiates.size();
    }

    bool find_first_candiate(const std::vector<std::vector<bool>>& flags, int& r, int& c)
    {
        for(int i=0; i<n_; ++i)
        {
            for(int j=0; j<n_; ++j)
            {
                if(!flags[i][j])
                {
                    r=i;
                    c=j;
                    return true;
                }
            }
        }
        return false;
    }

    void set_flags(int i, int j
            , std::vector<std::pair<int ,int>>& sets
            , std::vector<std::vector<bool>>& flags)
    {
        flags[i][j]=true;
        sets.push_back({i, j});

        for(int r=i, c=0; c<n_; ++c)
        {
            if(!flags[r][c] && c!=j)
            {
                flags[r][c]=true;
                sets.push_back({r, c});
            }
        }

        for(int r=0, c=j; r<n_; ++r)
        {
            if(!flags[r][c] && r!=i)
            {
                flags[r][c]=true;
                sets.push_back({r, c});
            }
        }

        for(int r=(i<j?0:i-j), c=(i<j?j-i:0); r<n_ && c<n_; ++r, ++c)
        {
            if(!flags[r][c] && r!=i)
            {
                flags[r][c]=true;
                sets.push_back({r, c});
            }
        }

        for(int r=(i+j<n_?0:i+j-n_+1), c=(i+j<n_?i+j:n_-1); r<n_ && c>=0; ++r, --c)
        {
            if(!flags[r][c] && r!=i)
            {
                flags[r][c]=true;
                sets.push_back({r, c});
            }
        }
    }

    void reset_flags(const std::vector<std::pair<int, int>>& resets
            , std::vector<std::vector<bool>>& flags)
    {
        for(size_t i=0; i<resets.size(); ++i)
            flags[resets[i].first][resets[i].second]=false;
    }

private:
    int n_;
    int cnt_;
};

class SolutionLeetCode
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::string>cur(n, std::string(n,'.'));
        helper(cur, 0);
        return res;
    }

    void helper(std::vector<std::string> &cur, int row)
    {
        if(row == cur.size())
        {
            res.push_back(cur);
            return;
        }
        for(int col = 0; col < cur.size(); col++)
            if(isValid(cur, row, col))
            {
                cur[row][col] = 'Q';
                helper(cur, row+1);
                cur[row][col] = '.';
            }
    }

    //判断在cur[row][col]位置放一个皇后，是否是合法的状态
    //已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    bool isValid(std::vector<std::string> &cur, int row, int col)
    {
        //列
        for(int i = 0; i < row; i++)
            if(cur[i][col] == 'Q')return false;
        //右对角线(只需要判断对角线上半部分，因为后面的行还没有开始放置)
        for(int i = row-1, j=col-1; i >= 0 && j >= 0; i--,j--)
            if(cur[i][j] == 'Q')return false;
        //左对角线(只需要判断对角线上半部分，因为后面的行还没有开始放置)
        for(int i = row-1, j=col+1; i >= 0 && j < cur.size(); i--,j++)
            if(cur[i][j] == 'Q')return false;
        return true;
    }

private:
    std::vector<std::vector<std::string> > res;

};

//上述判断状态是否合法的函数还是略复杂，其实只需要用一个一位数组来存放当前皇后的状态。假设数组为int state[n], state[i]表示第 i 行皇后所在的列。那么在新的一行 k 放置一个皇后后:
//判断列是否冲突，只需要看state数组中state[0…k-1] 是否有和state[k]相等；
//判断对角线是否冲突：如果两个皇后在同一对角线，那么|row1-row2| = |column1 - column2|，（row1，column1），（row2，column2）分别为冲突的两个皇后的位置
using namespace std;
class SolutionLeetCode2
{
private:
    vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> state(n, -1);
        helper(state, 0);
        return res;
    }
    void helper(vector<int> &state, int row)
    {//放置第row行的皇后
        int n = state.size();
        if(row == n)
        {
            vector<string>tmpres(n, string(n,'.'));
            for(int i = 0; i < n; i++)
                tmpres[i][state[i]] = 'Q';
            res.push_back(tmpres);
            return;
        }
        for(int col = 0; col < n; col++)
            if(isValid(state, row, col))
            {
                state[row] = col;
                helper(state, row+1);
                state[row] = -1;;
            }
    }
     
    //判断在row行col列位置放一个皇后，是否是合法的状态
    //已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    bool isValid(vector<int> &state, int row, int col)
    {
        for(int i = 0; i < row; i++)//只需要判断row前面的行，因为后面的行还没有放置
            if(state[i] == col || abs(row - i) == abs(col - state[i]))
                return false;
        return true;
    }
};

class SolutionLeetCode2Itr
{
private:
    vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> state(n, -1);
        for(int row = 0, col; ;)
        {
            for(col = state[row] + 1; col < n; col++)//从上一次放置的位置后面开始放置
            {
                if(isValid(state, row, col))
                {
                    state[row] = col;
                    if(row == n-1)//找到了一个解,继续试探下一列
                    {
                        vector<string>tmpres(n, string(n,'.'));
                        for(int i = 0; i < n; i++)
                            tmpres[i][state[i]] = 'Q';
                        res.push_back(tmpres);
                    }
                    else {row++; break;}//当前状态合法，去放置下一行的皇后
                }
            }
            if(col == n)//当前行的所有位置都尝试过，回溯到上一行
            {
                if(row == 0)break;//所有状态尝试完毕，退出
                state[row] = -1;//回溯前清除当前行的状态
                row--;
            }
        }
        return res;
    }
     
    //判断在row行col列位置放一个皇后，是否是合法的状态
    //已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    bool isValid(vector<int> &state, int row, int col)
    {
        for(int i = 0; i < row; i++)//只需要判断row前面的行，因为后面的行还没有放置
            if(state[i] == col || abs(row - i) == abs(col - state[i]))
                return false;
        return true;
    }
};

int main()
{
    Solution s;
    std::cout<<s.totalNQueens(8)<<std::endl;
    return 0;
}

