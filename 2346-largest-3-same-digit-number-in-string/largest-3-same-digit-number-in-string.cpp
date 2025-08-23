class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        if (n < 3) return "";
        string res = "";
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string candidate = num.substr(i, 3);
                if (res.empty() || candidate > res) res = candidate;
            }
        }
        return res;
    }
};