class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> frequencyMap;
        for (const auto &num : nums)
        {
            frequencyMap[num]++;
            if (frequencyMap[num] > 1)
                return true;
        }
        return false;
    }
};
// Worst solution