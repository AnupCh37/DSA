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
    queue<TreeNode *> q;
    TreeNode *temp;
    void flatten(TreeNode *root)
    {
        if (root)
        {
            preOrder(root);
            root->left = nullptr;
            root->right = nullptr;
            q.pop();
            temp = root;
            while (!q.empty())
            {
                temp->left = nullptr;
                temp->right = q.front();
                q.pop();
                temp = temp->right;
            }
            temp->left = nullptr;
            temp->right = nullptr;
        }
    }

    void preOrder(TreeNode *root)
    {
        if (root)
        {
            q.push(root);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};