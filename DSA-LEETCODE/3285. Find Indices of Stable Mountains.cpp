class Solution
{
public:
    vector<int> stableMountains(vector<int> &height, int threshold)
    {
        vector<int> Stable;
        for (size_t i = 1; i < height.size(); i++)
        {
            if (height[i - 1] > threshold)
                Stable.push_back(i);
        }
        return Stable;
    }
};