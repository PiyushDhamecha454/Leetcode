class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.size() - 1, s2 = num2.size() - 1, c = 0;     
        string res = "";
        while (s1 >= 0 || s2 >= 0 || c != 0) {
            int d1 = (s1 >= 0) ? num1[s1] - '0' : 0;
            int d2 = (s2 >= 0) ? num2[s2] - '0' : 0;
            int sum = d1 + d2 + c;
            c = sum / 10;
            res += to_string(sum % 10);
            s1--;
            s2--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};