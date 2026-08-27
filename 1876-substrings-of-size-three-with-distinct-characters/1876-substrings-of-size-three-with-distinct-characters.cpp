class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        for (int i = 0; i < n - 2; ++i) {
            // Check if all three characters in the current window are distinct
            if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) {
                count++;
            }
        }
        
        return count;
    }
};