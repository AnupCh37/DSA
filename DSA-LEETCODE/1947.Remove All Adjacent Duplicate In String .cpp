class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string result;
        for( auto & ch :s){
          if(!st.empty() && ch==st.top()){
            st.pop();
          }
          else {
          st.push(ch);}
        }
        while(!st.empty()){
        result=result+st.top();
        st.pop();
        }
         reverse(result.begin(),result.end());
         return result;
    }
};
// worst case bad runtime and space complexity 