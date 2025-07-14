class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";
        set<char> st(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (!(st.count(tolower(s[i])) && st.count(toupper(s[i])))) {
                string s1 = longestNiceSubstring(s.substr(0, i));
                string s2 = longestNiceSubstring(s.substr(i + 1));
                return s2.size() > s1.size() ? s2 : s1;
            }
        }
        return s;
    }
};