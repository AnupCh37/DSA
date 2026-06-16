class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        for (const auto num : nums2)
        {
            nums1.push_back(num);
        }
        sort(nums1.begin(), nums1.end());
        int len = nums1.size();
        if (len % 2 != 0)
        {
            return nums1[(len + 1) / 2 - 1];
        }
        else
        {
            return (nums1[len / 2 - 1] + nums1[len / 2]) / 2.000;
        }
    }
};