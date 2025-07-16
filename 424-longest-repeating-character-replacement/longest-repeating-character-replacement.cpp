class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, mL = 0, mF = 0;
        vector<int> v(26, 0);

        for (int r = 0; r < s.size(); r++) {
            v[s[r] - 'A']++;
            mF = max(mF, v[s[r] - 'A']);
            while (r - l + 1 - mF > k) {
                v[s[l] - 'A']--;
                mF = 0;
                for (int i = 0; i < 26; i++) mF = max(mF, v[i]);
                l++;
            }
            if (r - l + 1 - mF <= k) mL = max(mL, r - l + 1);
        }
        
        return mL;
    }
};