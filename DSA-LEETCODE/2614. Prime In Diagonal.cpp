class Solution
{
public:
    int diagonalPrime(vector<vector<int>> &nums)
    {
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j && isPrime(nums[i][j]))

                    v.push_back(nums[i][j]);

                else if (i + j == nums.size() - 1 && i != j && isPrime(nums[i][j]))
                    v.push_back(nums[i][j]);
            }
        }
        sort(v.rbegin(), v.rend());
        if (!v.empty())
            return v[0];
        return 0;
    }
    bool isPrime(int x)
    {
        int count = 0;
        if (x < 2)
        {
            return false;
        }
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
// This and sqrt bad;