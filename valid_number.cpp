#include<iostream>
#include<cassert>
#include<string>

/*
先枚举一下各种合法的输入情况：

1.空格+ 数字 +空格

2.空格+ 点 + 数字 +空格

3.空格+ 符号 + 数字 +　空格

4.空格 + 符号 + 点 +　数字　＋空格

5.空格 + (1, 2, 3, 4)[除去空格] + e +　(1, 2, 3, 4) + 空格
*/

class SolutionLeetCode
{
public:
    bool isNumber(const std::string s)
    {
        enum InputType
        {
            INVALID,        // 0 Include: Alphas, '(', '&' ans so on
            SPACE,      // 1
            SIGN,       // 2 '+','-'
            DIGIT,      // 3 numbers
            DOT,            // 4 '.'
            EXPONENT,       // 5 'e' 'E'
        };

        int transitionTable[][6] = {
        //0INVA,1SPA,2SIG,3DI,4DO,5E
            {-1,  0,  3,  1,  2, -1},//0初始无输入或者只有space的状态
            {-1,  8, -1,  1,  4,  5},//1输入了数字之后的状态
            {-1, -1, -1,  4, -1, -1},//2前面无数字，只输入了Dot的状态
            {-1, -1, -1,  1,  2, -1},//3输入了符号状态
            {-1,  8, -1,  4, -1,  5},//4前面有数字和有dot的状态
            {-1, -1,  6,  7, -1, -1},//5'e' or 'E'输入后的状态
            {-1, -1, -1,  7, -1, -1},//6输入e之后输入Sign的状态
            {-1,  8, -1,  7, -1, -1},//7输入e后输入数字的状态
            {-1,  8, -1, -1, -1, -1},//8前面有有效数输入之后，输入space的状态
        };

        int state = 0;
        for(char c : s)
        {
            InputType inputType = INVALID;
            if (isspace(c))
                inputType = SPACE;
            else if (c == '+' || c == '-')
                inputType = SIGN;
            else if (isdigit(c))
                inputType = DIGIT;
            else if (c == '.')
                inputType = DOT;
            else if (c == 'e' || c == 'E')
                inputType = EXPONENT;
            
            state = transitionTable[state][inputType];
            
            if (state == -1)
                return false;
        }

        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};

int main()
{
    SolutionLeetCode s;
    std::cout<<std::endl;
    return 0;
}

