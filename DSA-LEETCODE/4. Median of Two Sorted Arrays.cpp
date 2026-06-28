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
        if (nums1.size() % 2 != 0)
        {
            return nums1[(nums1.size() + 1) / 2 - 1];
        }
        return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2.000;
    }
};