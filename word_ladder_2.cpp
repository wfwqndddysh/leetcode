#include<climits>
#include<iostream>
#include<cassert>
#include<string>
#include<unordered_set>
#include<vector>
#include<queue>

class Solution
{
public:
    std::vector<std::vector<std::string>> findLadders(std::string beginWord
            , std::string endWord
            , std::unordered_set<std::string> &wordDict)
    {
        std::vector<std::vector<std::string>> vvs;
        if(beginWord==endWord) return vvs;
        if(wordDict.count(beginWord)==0 || wordDict.count(endWord)==0) return vvs;

        int min_length{INT_MAX};
        int cur_length{1};
        std::queue<std::pair<std::string, std::vector<std::string>>> bfs;
        bfs.push({beginWord, {beginWord}});
        wordDict.erase(beginWord);

        int last_level=1;
        int cur_level=0;
        while(!bfs.empty() && cur_length<=min_length)
        {
            auto cur=bfs.front();
            bfs.pop();

            for(size_t i=0; i<cur.first.length(); ++i)
            {
                char tmp = cur.first[i];
                for(char c='a'; c<='z'; ++c)
                {
                    if(c==cur.first[i]) continue;

                    cur.first[i]=c;

                    if(cur.first==endWord)
                    {
                        min_length = cur_length;
                        cur.second.push_back(cur.first);
                        vvs.push_back(cur.second);
                        goto next;
                    }

                    auto itr=wordDict.find(cur.first);
                    if(itr!=wordDict.cend())
                    {
                        //wordDict.erase(itr);
                        std::vector<std::string> v{cur.second};
                        v.push_back(cur.first);
                        bfs.push({cur.first, v});
                        cur_level++;
                    }
                }
                cur.first[i] = tmp;
            }

next:
            last_level--;
            if(last_level==0)
            {
                last_level=cur_level;
                cur_level = 0;
                cur_length++;
            }
        }
        return vvs;
    }
};

int main()
{
    Solution s;

    //std::string a("hit");
    //std::string b("cog");
    //std::unordered_set<std::string> dict{"hot","cog","dot","dog","hit","lot","log"};

    //std::string a("red");
    //std::string b("tax");
    //std::unordered_set<std::string> dict{"ted","tex","red","tax","tad","den","rex","pee"};

    std::string a("cet");
    std::string b("ism");
    std::unordered_set<std::string> dict{"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};

    auto vvs = s.findLadders(a, b, dict);
    for(const auto& v : vvs)
    {
        for(const auto& s : v)
        {
            std::cout<<s<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return 0;
}

