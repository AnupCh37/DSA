class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int lastElement = nums[0], result, currentElement;
        for (int i = 0; i < nums.size(); i++)
        {
            currentElement = nums[i];
            if (lastElement != currentElement && i % 2 != 0)
            {
                result = lastElement;
                break;
            }
            lastElement = nums[i];
        }
        return result;
    }
};