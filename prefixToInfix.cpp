class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        int n = pre_exp.size();
        for (int i = n - 1; i >= 0; i--) {
            char c = pre_exp[i];
            if (isalpha(c) || isdigit(c)) st.push(string(1, c));
            else {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string temp = "(" + op1 + c + op2 + ")";
                st.push(temp);
            }
        }
        return st.top();
    }
};