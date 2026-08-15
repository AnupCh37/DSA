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
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        int n;
        vector<double> result;
        TreeNode *temp;
        double sum;
        while (!q.empty())
        {
            n = q.size();
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                sum += temp->val;
            }
            result.push_back(sum / n);
        }
        return result;
    }
};