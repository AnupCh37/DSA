/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> dq;
        int length = 0, n;
        TreeNode *temp;
        dq.push(root);
        while (!dq.empty())
        {
            n = dq.size();
            for (int i = 0; i < n; i++)
            {
                temp = dq.front();
                dq.pop();
                if (temp->left)
                    dq.push(temp->left);
                if (temp->right)
                    dq.push(temp->right);
            }
            length++;
        }
        return length;
    }
};