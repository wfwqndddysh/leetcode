#include<iostream>
#include<cassert>
#include<string>
#include<vector>

class Solution
{
public:
    std::string simplifyPath(std::string path)
    {
        size_t len=path.length();
        if(len==0) return "";
        std::string simple("/");

        for(size_t i=0; i<len; )
        {
            if(path[i]=='/')
            {
                eat_slash(path, i);
                if((i!=len && simple.back()!='/'))
                {
                    simple.push_back('/');
                }
            }
            else if(path[i]=='.')
            {
                if(i==len-1)
                {
                    if(simple.length()>1) simple.pop_back();
                    break;
                }

                i++;
                if(path[i]=='/')
                {
                    eat_slash(path, i);
                    if(i==len)
                    {
                        if(simple.length()>1) simple.pop_back();
                    }
                }
                else if(path[i]=='.')
                {
                    i++;
                    if(i==len || path[i]=='/')
                    {
                        pop_dir(simple);
                    }
                    else
                    {
                        simple.push_back('.');
                        simple.push_back('.');
                        while(path[i]=='.' && i<len)
                        {
                            simple.push_back('.');
                            i++;
                        }
                    }
                }
                else
                {
                    simple.push_back('.');
                }
            }
            else
            {
                simple.push_back(path[i++]);
            }
        }

        return simple;
    }

private:
    void eat_slash(const std::string& path, size_t& i)
    {
        size_t len=path.length();
        while(path[i]=='/' && i<len) i++;
    }

    void pop_dir(std::string& simple)
    {
        assert(simple.length()>=1);
        if(simple.length()==1)
            return;

        simple.pop_back();

        while(simple.back()!='/') simple.pop_back();

        if(simple.length()>1) simple.pop_back();
    }
};


class SolutionLeetCode
{
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        assert(path[0]=='/');

        size_t i=0;
        while(i< path.size())
        {
            while(path[i] =='/' && i< path.size()) i++; //skip the begining '////'
            if(i == path.size()) break;

            int start = i;
            while(path[i]!='/' && i< path.size()) i++; //decide the end boundary
            int end = i-1;
            std::string element = path.substr(start, end-start+1);

            if(element == "..")
            {
                if(stack.size() >0) stack.pop_back();
            }
            else if(element!=".")
            {
                stack.push_back(element);
            }
        }

        if(stack.size() ==0) return "/";

        std::string simpPath;
        for(size_t i =0; i<stack.size(); i++) simpPath += "/" + stack[i];

        return simpPath;
    }
};

int main()
{
    Solution s;
    //std::string path("/");
    //std::string path("/a/./b/../../c/");
    //std::string path("jaxjp/./");
    std::string path("/");
    std::cout<<s.simplifyPath(path)<<std::endl;
    return 0;
}

