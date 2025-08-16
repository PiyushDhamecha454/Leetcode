class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        map<char, int> mp;
        int c = 0, l = 0, sI = -1, minL = INT_MAX;
        for (int i = 0; i < t.size(); i++) mp[t[i]]++;
        for (int r = 0; r < s.size(); r++) {
            if (mp[s[r]] > 0) c++;
            mp[s[r]]--;
            while (c == t.size()) {
                if (r - l + 1 < minL) {
                    minL = r - l + 1;
                    sI = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) c--;
                l++;
            }
        }
        return sI == -1 ? "" : s.substr(sI, minL);
    }
};