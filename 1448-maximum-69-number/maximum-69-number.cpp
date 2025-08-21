class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        for (char &c : n) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        num = stoi(n);
        return num;
    }
};