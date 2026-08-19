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
    ListNode *removeNodes(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        deque<int> stackList;
        stackList.push_back(temp->val);
        while (temp != nullptr)
        {
            if (stackList.back() >= temp->val)
            {
                stackList.push_back(temp->val);
            }
            else if (temp->val > stackList.back())
            {
                while (!stackList.empty() && stackList.back() < temp->val)
                {
                    stackList.pop_back();
                }
                stackList.push_back(temp->val);
            }
            temp = temp->next;
        }
        temp = head;
        ListNode *pretemp;
        while (!stackList.empty() && temp != nullptr)
        {
            pretemp = temp;
            temp->val = stackList.front();
            temp = temp->next;
            stackList.pop_front();
        }
        pretemp->next = nullptr;
        return head;
    }
};