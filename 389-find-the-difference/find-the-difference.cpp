class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mp;
        for(char c: s) mp[c]++;
        for(char c: t){
            if(mp[c] > 0) mp[c]--;
            else return c;
        }
        return '\0';
    }
};