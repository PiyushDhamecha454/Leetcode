class Solution {
public:
bool isPalindrome(string s, int start, int end) {
    while (start <= end) if (s[start++] != s[end--]) return false;
    return true;
}

void helper (string s, vector<vector<string>>& res, vector<string>& temp, int index, int n) {
    if (index == n) {
        res.push_back(temp);
        return;
    }
    for (int i = index; i < n; i++) {
        if (isPalindrome(s, index, i)) {
            temp.push_back(s.substr(index, i - index + 1));
            helper(s, res, temp, i + 1, n);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> temp;
    int n = s.size();
    helper(s, res, temp, 0, n);
    return res;
}
};