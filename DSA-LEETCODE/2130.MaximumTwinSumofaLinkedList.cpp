/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *temp = head;
        deque<int> dq;
        while (temp != nullptr)
        {
            dq.push_back(temp->val);
            temp = temp->next;
        }
        int maxsum = 0;
        int sum;
        while (!dq.empty())
        {
            sum = dq.front() + dq.back();
            if (sum > maxsum)
                maxsum = sum;
            dq.pop_back();
            dq.pop_front();
        }
        return maxsum;
    }
};