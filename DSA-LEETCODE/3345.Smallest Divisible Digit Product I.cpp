class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        int product;
        while (true)
        {
            product = productDigits(n);
            if (product % t == 0)
                return n;
            n++;
        }
        return n;
    }
    int productDigits(int n)
    {
        int product = 1, rem = 0;
        while (n != 0)
        {
            rem = n % 10;
            product *= rem;
            n /= 10;
        }
        return product;
    }
};