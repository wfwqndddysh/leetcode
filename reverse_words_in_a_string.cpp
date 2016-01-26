#include<iostream>
#include<cassert>
#include<string>

//这个问题的思路在于先reverse整个string,再reverse每个string
//关于去掉头尾和中间dup的space，维护两个 read/write pointer 就够了

//http://www.ardendertat.com/2011/10/31/programming-interview-questions-12-reverse-words-in-a-string/
class Solution
{
public:
    void reverseWords(std::string& s)
    {
        if(s.empty()) return;

        auto sz=s.size();
        size_t read = 0;
        size_t write = 0;

        //reverse while
        reverseString(s, 0, sz-1, 0);

        //reverse each
        for(; read<sz; read++)
        {
            if(s[read]!=' ')
            {
                size_t word_start = read;
                while(s[read]!=' ' && read<sz) read++;
                reverseString(s, word_start, read-1, write);
                write += read-word_start;
                s[write++] =  ' ';
            }
        }

        if(write>0) write--; //last ' '

        for(size_t i=write; i<sz; ++i)
        {
            s.erase(--s.end());
        }
        //s[write] =  '\0';
    }

    void reverseString(std::string& s, size_t beg, size_t end, size_t dest)
    {
        if(beg!=dest)
        {
            for(size_t i=0; i<end-beg+1; ++i)
                s[dest+i] = s[beg+i];
        }

        for(size_t b=dest, e=dest+end-beg; b<e; ++b, --e)
        {
            auto tmp = s[e];
            s[e] = s[b];
            s[b] = tmp;
        }
    }
};

int main()
{
    Solution s;
    //std::string str = " the sky is blue  ";
    std::string str = " 1";
    s.reverseWords(str);
    std::cout<<str.size()<<std::endl;
    std::cout<<str<<std::endl;
    return 0;
}

