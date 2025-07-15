class Solution {
public:
    int numberOfSubstrings(string s) {
        int c = 0, n = s.size();
        vector<int> last(3, -1);
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
            if (last[0] != -1 && last[1] != -1 && last[2] != -1) c += 1 + min(last[0], min(last[1], last[2]));
        }
        return c;
    }
};