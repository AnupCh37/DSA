class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        vector<int> result;
        for (const auto num : nums)
        {
            if (num > largest)
                largest = num;
            if (num < smallest)
                smallest = num;
        }

        sort(nums.begin(), nums.end());
        int j = 0;
        for (int i = smallest; i < largest; i++)
        {
            if (nums[j] != i)
            {
                result.push_back(i);
            }
            else
            {
                j++;
            }
        }
        return result;
    }
};
// both nice btw
// time nlongn
// space n;