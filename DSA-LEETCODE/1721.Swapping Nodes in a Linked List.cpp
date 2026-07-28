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
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        int length = 0;
        while (temp != nullptr)
        {
            length++;
            temp = temp->next;
        }
        ListNode *pretemp = head;
        temp = head;
        int n = k;
        while (n != 0)
        {
            pretemp = temp;
            temp = temp->next;
            n--;
        }
        temp = head;
        n = length - k;
        while (n != 0)
        {
            temp = temp->next;
            n--;
        }
        int tempVal;
        tempVal = temp->val;
        temp->val = pretemp->val;
        pretemp->val = tempVal;
        return head;
    }
};