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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        ListNode *pretemp;
        ListNode *ptr;
        while (temp->next != nullptr)
        {
            pretemp = temp;
            temp = temp->next;
            ptr = gcd(pretemp->val, temp->val);
            pretemp->next = ptr;
            ptr->next = temp;
        }
        return head;
    }

    ListNode *gcd(int a, int b)
    {
        if (b == 0)
            return new ListNode(a);
        return gcd(b, a % b);
    }
};