class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> numFrequency;
        for (const auto &num : nums)
        {
            numFrequency[num]++;
        }
        int element;
        int maxFrequency = 0;
        for (const auto &pair : numFrequency)
        {
            if (pair.second > maxFrequency)
            {
                maxFrequency = pair.second;
                element = pair.first;
            }
        }
        return element;
    }
};