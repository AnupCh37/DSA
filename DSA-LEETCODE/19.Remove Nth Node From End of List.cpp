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
    int length = 0;
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            length++;
            temp = temp->next;
        }
        if (length == 0 || length == 1)
            return NULL;
        length -= n;
        temp = head;
        if (length == 0)
        {
            head = head->next;
            return head;
        }
        ListNode *pretemp = temp;
        while (length != 0)
        {
            pretemp = temp;
            temp = temp->next;
            length--;
        }
        pretemp->next = temp->next;
        temp->next = nullptr;
        return head;
    }
};