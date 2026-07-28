class Solution
{
public:
    int maxProduct(int n)
    {
        vector<int> digits;
        while (n != 0)
        {
            digits.push_back(n % 10);
            n = n / 10;
        }
        if (digits.size() < 2)
            return 0;
        int largest = -1;
        int secondLargest = -1;
        for (const auto num : digits)
        {
            if (num > largest)
            {
                secondLargest = largest;
                largest = num;
            }
            else if (num > secondLargest)
            {
                secondLargest = num;
            }
        }

        return largest * secondLargest;
    }
};