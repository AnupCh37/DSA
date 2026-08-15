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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (!root)
            return {};
        stack<vector<int>> s;
        q.push(root);
        int n;
        TreeNode *temp;
        while (!q.empty())
        {
            n = q.size();
            vector<int> vtemp = {};
            for (int i = 0; i < n; i++)
            {
                temp = q.front();
                q.pop();
                vtemp.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            s.push(vtemp);
        }
        vector<vector<int>> vs;
        while (!s.empty())
        {
            vs.push_back(s.top());
            s.pop();
        }
        return vs;
    }
};