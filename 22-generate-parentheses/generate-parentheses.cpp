class Solution {
public:
    void helper(int openP, int closeP, string s, int n, vector<string>& res) {
    if (openP == closeP && openP + closeP == n * 2) {
        res.push_back(s);
        return;
    }
    if (openP < n) helper(openP + 1, closeP, s + "(", n, res);
    if (closeP < openP) helper(openP, closeP + 1, s + ")", n, res);
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    helper(0, 0, "", n, res);
    return res; 
}
};