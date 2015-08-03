#include<iostream>
#include<cassert>
#include<vector>
#include<string>

/*
class Solution
{
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words
            , int maxWidth)
    {
        int sz=words.size();
        std::vector<std::string> res;

        for(int i=0; i<sz; )
        {
            int w_len=0;
            int j=i;
            for(; j<sz; ++j)
            {
                int cur_word_len=words[j].length();
                int space_len=j-i;

                if(w_len + cur_word_len + space_len >= maxWidth)
                    break;

                w_len += cur_word_len;
            }

            std::string line;

            if(j==sz)
            {
                for(int k=i; k<j; ++k)
                {
                    line += words[k];
                    if(k<j-1) line.push_back(' ');
                }
            }
            else
            {
                int d=(maxWidth-w_len)/(j-i-1);
                int m=(maxWidth-w_len)%(j-i-1);

                for(int k=i; k<j; ++k)
                {
                    line += words[k];
                    for(int n=0; n<d; ++n)
                    {
                        line.push_back(' ');
                    }
                    
                    if(m-->0) line.push_back(' ');
                }
            }

            while((int)line.length()<maxWidth)
            {
                line.push_back(' ');
            }

            res.push_back(line);
            i=j;
        }

        return res;
    }
};
*/

class Solution
{
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words
            , int maxWidth)
    {
        int sz=words.size();
        std::vector<std::string> res;

        for(int i=0; i<sz; )
        {
            int row_len=0;
            int j=i;
            while(j < sz && row_len + (int)words[j].size() <= maxWidth)
                row_len += (words[j++].size() + 1);

            std::string line;
            if(j==sz || j-i==1)
            {
                for(int k=i; k<j; ++k)
                {
                    line += words[k];
                    if(k<j-1) line.push_back(' ');
                }
            }
            else
            {
                int w_len=row_len-(j-i);
                int d=(maxWidth-w_len)/(j-i-1);
                int m=(maxWidth-w_len)%(j-i-1);

                for(int k=i; k<j; ++k)
                {
                    line += words[k];

                    if(k==j-1) break;
                    for(int n=0; n<d; ++n)
                    {
                        line.push_back(' ');
                    }
                    
                    if(m-->0) line.push_back(' ');
                }
            }

            while((int)line.length()<maxWidth)
            {
                line.push_back(' ');
            }

            res.push_back(line);
            i=j;
        }

        return res;
    }
};

int main()
{
    Solution s;

    //std::vector<std::string> words{ "This", "is", "an", "example", "of", "text", "justification." };
    //auto vs=s.fullJustify(words, 16);

    std::vector<std::string> words{ "a", "b", "c", "d", "e" };
    auto vs=s.fullJustify(words, 3);

    for(const auto& str : vs)
    {
        std::cout<<str<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

