class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int i = 0;
        for (const auto &num : costs)
        {
            if (coins >= num)
            {
                coins -= num;
                i++;
            }
        }
        return i;
    }
};