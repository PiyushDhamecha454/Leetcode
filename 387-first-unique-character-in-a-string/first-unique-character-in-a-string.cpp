class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) mp[s[i]].second += 1;
            else mp[s[i]] = {i, 1};
        }
        int res = n;
        for (auto& p : mp) if (p.second.second == 1) res = min(res, p.second.first);
        return res == n ? -1 : res;
    }
};