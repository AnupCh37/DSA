class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int largestElement = -1;
        int secondLargest = -1;
        for (auto const num : nums)
        {
            if (num > largestElement)
            {
                secondLargest = largestElement;
                largestElement = num;
            }
            else if (num > secondLargest)
            {
                secondLargest = num;
            }
        }
        return (largestElement - 1) * (secondLargest - 1);
    }
};