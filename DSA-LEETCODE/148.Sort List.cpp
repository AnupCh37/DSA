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
    ListNode *sortList(ListNode *head)
    {
        vector<int> nums;
        if (!head || !head->next)
            return head;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        mergeSort(nums, 0, nums.size() - 1);
        temp = head;
        int i = 0;
        while (temp != nullptr)
        {
            temp->val = nums[i++];
            temp = temp->next;
        }
        return head;
    }
    void mergeSort(vector<int> &nums, int start, int end)
    {
        int mid = start + (end - start) / 2;
        if (start < end)
        {
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        int i = start;
        int j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= end)
        {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= end)
            temp.push_back(nums[j++]);
        for (int i = 0; i < temp.size(); i++)
            nums[i + start] = temp[i];
    }
};
// beat only 5* in both case
// use stack