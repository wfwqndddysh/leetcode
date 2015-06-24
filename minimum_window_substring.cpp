#include<iostream>
#include<cassert>
#include<string>

/*
1.初始化 start = i = 0
2.i逐渐往后扫描S直到窗口S[start…i]包含所有T的字符，此时i = 6（字符c的位置）
3.缩减窗口：此时我们注意到窗口并不是最小的，需要调整 start 来缩减窗口。缩减规则为：如果S[start]不在T中 或者 S[start]在T中但是删除后窗口依然可以包含T中的所有字符，那么start = start+1， 直到不满足上述两个缩减规则。缩减后i即为窗口的起始位置，此例中从e开始窗口中要依次删掉e、b、a、d，start最后等于4 ，那么得到一个窗口大小为6-4+1 = 3
4.start = start+1(此时窗口肯定不会包含所有的T中的字符)，跳转到步骤2继续寻找下一个窗口。本例中还以找到一个窗口start = 5，i = 8，比上个窗口大，因此最终的最小窗口是S[4…6]
*/

/*
想到了hashmap建字典
想到了使用计数来确定是是否找到了一个窗口，
没有想到用双指针来滑动窗口(关键是没有想到缩减窗口的办法)
*/

class Solution
{
public:
    std::string minWindow(std::string S, std::string T)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int lens = S.size(), lent = T.size();
        int srcCnt[256] = {0};//T中每个字母的个数
        int foundCnt[256] = {0};//当前找到T中每个字母的个数
        for(int i = 0; i < lent; i++)
            srcCnt[T[i]]++;
        int hasFound = 0;//已经找到的字母数目
        int winStart = -1, winEnd = lens;//窗口的左右边界
        //两个指针start和i一起扫描
        for(int i = 0, start = 0; i < lens; i++)
        {
            if(srcCnt[S[i]] != 0)
            {
                foundCnt[S[i]]++;
                if(foundCnt[S[i]] <= srcCnt[S[i]])hasFound++;

                if(hasFound == lent)//找到了一个满足的窗口
                {
                    while(srcCnt[S[start]] == 0 || foundCnt[S[start]] > srcCnt[S[start]])//缩减窗口
                    {
                        if(srcCnt[S[start]] != 0)
                            foundCnt[S[start]]--;
                        start++;
                    }
                    if(winEnd - winStart > i - start)
                    {
                        winStart = start;
                        winEnd = i;
                    }
                    foundCnt[S[start]]--;
                    start++;
                    hasFound--;
                }
            }
        }
        return winStart != -1 ? S.substr(winStart, winEnd - winStart +1) : "";
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

