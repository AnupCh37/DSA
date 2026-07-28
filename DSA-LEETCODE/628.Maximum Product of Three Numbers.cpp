class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size() - 1;
        if (len < 2)
            return -1;
        int allPos = nums[len] * nums[len - 1] * nums[len - 2];
        int twoNeg = nums[0] * nums[1] * nums[len];
        if (allPos > twoNeg)
            return allPos;
        return twoNeg;
    }
};