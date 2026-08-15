class Solution
{
public:
    vector<int> temp;
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(vector<int> &nums, int left, int right)
    {
        int mid = left + (right - left) / 2;
        if (left < right)
        {
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int i = left;
        int j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= right)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for (int i = 0; i < temp.size(); i++)
        {
            nums[left + i] = temp[i];
        }
    }
};