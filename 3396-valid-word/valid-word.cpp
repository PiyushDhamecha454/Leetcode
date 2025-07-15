class Solution {
    bool isNum (char c) {
        return c >= '0' && c <= '9';
    }
    bool isChar (char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');  
    }
    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    bool isConsonant (char c) {
        return !isVowel(c) && isChar(c);
    }
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        int n = word.size();
        bool hV = false, hC = false;
        for (char c : word) {
            if (!isNum(c) && !isChar(c)) return false;
            if (isVowel(c)) hV = true;
            if (isConsonant(c)) hC = true;
        }
        return hV && hC;
    }
};