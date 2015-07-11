#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int m=nums1.size();
        int n=nums2.size();
        int half=(m+n+1)/2;

        int low(0);
        int high(m);
        int mid(-1);
        std::vector<int>* master=&nums1;
        std::vector<int>* slaver=&nums2;

        if(n<m)
        {
            high=n;
            master=&nums2;
            slaver=&nums1;
        }

        bool odd=((m+n)&1)==1;
        while(low<=high)
        {
            mid=low+(high-low)/2;

            int slaver_mid=half-mid;

            if(mid>0 && slaver_mid<std::max(m, n) && (*master)[mid-1]>(*slaver)[slaver_mid])
            {
                high=mid-1;
            }
            else if(slaver_mid>0 && mid<std::min(m, n) && (*slaver)[slaver_mid-1]>(*master)[mid])
            {
                low=mid+1;
            }
            else
            {
                int n1;
                int n2;
                if(mid==0)
                {
                    n1=(*slaver)[slaver_mid-1];
                }
                else if(slaver_mid==0)
                {
                    n1=(*master)[mid-1];
                }
                else
                {
                    n1=std::max((*master)[mid-1], (*slaver)[slaver_mid-1]);
                }

                if(odd) return n1;

                if(mid==std::min(m, n))
                {
                    n2=(*slaver)[slaver_mid];
                }
                else if(slaver_mid==std::max(m, n))
                {
                    n2=(*master)[mid];
                }
                else
                {
                    n2=std::min((*master)[mid], (*slaver)[slaver_mid]);
                }

                return (n1+n2)/2.0;
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;

    /*
    std::vector<int> nums1;
    std::vector<int> nums2{1};
    */

    /*
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{1, 2, 3};
    */

    /*
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{1, 2};
    */

    /*
    std::vector<int> nums1{1};
    std::vector<int> nums2{1};
    */

    std::vector<int> nums1{2};
    std::vector<int> nums2{};
    std::cout<<s.findMedianSortedArrays(nums1, nums2)<<std::endl;
    return 0;
}

