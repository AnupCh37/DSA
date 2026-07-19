class Solution
{
public:
    vector<int> prefixGcd;
    long long sum = 0;
    int mxi;
    long long gcdSum(vector<int> &nums)
    {
        int currentMax = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            mxi = findMxi(nums[i], currentMax);
            prefixGcd.push_back(gcd(nums[i], mxi));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        for (int i = 0; i < prefixGcd.size() / 2; i++)
        {
            sum += gcd(prefixGcd[i], prefixGcd[prefixGcd.size() - 1 - i]);
        }
        return sum;
    }
    int findMxi(int num, int &currentMax)
    {
        if (num > currentMax)
            currentMax = num;
        return currentMax;
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
// bad runtime and space 30%