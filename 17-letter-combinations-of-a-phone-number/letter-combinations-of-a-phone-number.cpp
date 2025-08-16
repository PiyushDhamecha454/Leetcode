class Solution {
public:
    unordered_map<char, string> keypad = {
    {'\0', ""},
    {'\n', ""},
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

void helper(string& digits, string& current, int index, int n, vector<string>& res) {
    if (index == n) {
        res.push_back(current);
        return;
    }

    string letters = keypad[digits[index]];
    for (char l : letters) {
        current.push_back(l);
        helper(digits, current, index + 1, n, res);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) return res;
    string current;
    int n = digits.size();
    helper(digits, current, 0, n, res);
    return res;
}
};