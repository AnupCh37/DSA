class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        map<int, string> people;
        for (int i = 0; i < names.size(); i++)
        {
            people[heights[i]] = names[i];
        }
        names.clear();
        for (auto it = people.rbegin(); it != people.rend(); ++it)
        {
            names.push_back(it->second);
        }
        return names;
    }
};