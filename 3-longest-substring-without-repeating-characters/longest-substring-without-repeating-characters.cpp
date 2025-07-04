class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, mL = 0;
        set<char> st;
        for (int r = 0; r < s.size(); r++) {
            while (st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            mL = max(mL, r - l + 1);
        }
        return mL;
    }
};