#include<iostream>
#include<cassert>
#include<vector>

//参考连接
//http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
//geeksforgeeks

/*
1. Initialize current as root
2. While current is not NULL
   If current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as right child of the rightmost node in current's left subtree
      b) Go to this left child, i.e., current = current->left

Function to traverse binary tree without recursion and without stack

那么，基于这个双指针遍历，可以把错置节点的判断逻辑加进去，就可以完美的在O(1)空间内，
完成树的重构。改动代码如红字所示。增加了一个pointer -- parent来记录上一个访问节点。
整个遍历过程中，使用（parent->val > current->val）来寻找违规节点，但是区别是，
要获取第一次violation的parent和第二次violation的current，然后交换。
*/

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *f1=NULL, *f2=NULL;
        TreeNode  *current,*pre, *parent=NULL;

        if(root == NULL)
            return;
        bool found = false;
        current = root;
        while(current != NULL)
        {
            if(current->left == NULL)
            {
                if(parent && parent->val > current->val)
                {
                    if(!found)
                    {
                        f1 = parent;
                        found = true;
                    }
                    f2 = current;
                }
                parent = current;
                current = current->right;
            }
            else
            {
                /* Find the inorder predecessor of current */
                pre = current->left;
                while(pre->right != NULL && pre->right != current)
                    pre = pre->right;

                /* Make current as right child of its inorder predecessor */
                if(pre->right == NULL)
                {
                    pre->right = current;
                    current = current->left;
                }

                /* Revert the changes made in if part to restore the original
                   tree i.e., fix the right child of predecssor */
                else
                {
                    pre->right = NULL;
                    if(parent->val > current->val)
                    {
                        if(!found)
                        {
                            f1 = parent;
                            found = true;
                        }
                        f2 = current;
                    }
                    parent = current;
                    current = current->right;
                } /* End of if condition pre->right == NULL */
            } /* End of if condition current->left == NULL*/
        } /* End of while */

        if(f1 && f2)
            std::swap(f1->val, f2->val);
    }

private:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        TreeNode  *current,*pre;

        if(root == NULL)
            return result;

        current = root;
        while(current != NULL)
        {
            if(current->left == NULL)
            {
                result.push_back(current->val);
                current = current->right;
            }
            else
            {
                /* Find the inorder predecessor of current */
                pre = current->left;
                while(pre->right != NULL && pre->right != current)
                    pre = pre->right;

                /* Make current as right child of its inorder predecessor */
                if(pre->right == NULL)
                {
                    pre->right = current;
                    current = current->left;
                }

                /* Revert the changes made in if part to restore the original
                   tree i.e., fix the right child of predecssor */
                else
                {
                    pre->right = NULL;
                    result.push_back(current->val);
                    current = current->right;
                } /* End of if condition pre->right == NULL */
            } /* End of if condition current->left == NULL*/
        } /* End of while */

        return result;
    }

};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

