#include <string>
class Solution {
public:
    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    string infixToPostfix(string &exp)
    {
        stack<char> st;
        string result = "";
        for (int i = 0; i < exp.size(); i++)
        {
            char c = exp[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                result += c;
            else if (c == '(')
                st.push('(');
            else if (c == ')')
            {
                while (st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && precedence(c) <= precedence(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        return result;
    }
}