class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st;
        int x = 0;
        int tempRemove;
        for (auto ch : operations)
        {
            if (ch == "C")
                st.pop();
            else if (ch == "D")
                st.push(st.top() * 2);
            else if (ch == "+")
            {
                tempRemove = st.top();
                st.pop();
                x = st.top() + tempRemove;
                st.push(tempRemove);
                st.push(x);
            }
            else
            {
                st.push(stoi(ch));
            }
        }
        x = 0;
        while (!st.empty())
        {
            x += st.top();
            st.pop();
        }
        return x;
    }
};
//Worst Solution only 40% beat
