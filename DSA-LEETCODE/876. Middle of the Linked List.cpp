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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *curr1 = head;
        int length = 0;
        while (curr1 != NULL)
        {
            length++;
            curr1 = curr1->next;
        }
        ListNode *curr = head;
        int i = 1;
        ;
        while (!(i == (length / 2) + 1))
        {
            curr = curr->next;
            i++;
        }
        return curr;
    }
};