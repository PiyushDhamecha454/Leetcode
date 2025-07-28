class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5) return false;
        int f = 0, t = 0;
        for (auto& x : bills) {
            if (x == 5) f++;
            else if (x == 10) {
                if (f > 0) f--;
                else return false;
                t++;
            }
            else {
                if (f > 0 && t > 0) {
                    f--;
                    t--;
                }
                else if (f > 2) f -= 3;
                else return false;
            }
        }
        return true;
    }
};