class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int a, b;
        for (string i : tokens) {
            if (i != "+" && i != "-" && i != "*" && i != "/") st.push(i);
            else {
                a = stoi(st.top());
                st.pop();
                b = stoi(st.top());
                st.pop();
                if (i == "+") st.push(to_string(b + a));
                else if (i == "-") st.push(to_string(b - a));
                else if (i == "*") st.push(to_string(b * a));
                else if (i == "/") st.push(to_string(b / a));
            }
        }
        return stoi(st.top());
    }
};