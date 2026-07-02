class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> frequencyMap;
        int x;
        for (const auto &num : nums)
        {
            frequencyMap[num]++;
        }
        for (const auto &pair : frequencyMap)
        {
            {
                if (pair.second == 1)
                    x = pair.first;
            }
        }
        return x;
    }
};
//worst 11.2% 7.3%
