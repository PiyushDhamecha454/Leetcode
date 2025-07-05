class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for (int x : arr) mp[x]++;
        int mLN = -1;
        for (auto& p : mp) if (p.first == p.second && p.first > mLN) mLN = p.first;
        return mLN;
    }
};