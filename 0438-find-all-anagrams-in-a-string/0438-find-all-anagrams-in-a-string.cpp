class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int s_len = s.length();
        int p_len = p.length();
        
        if (s_len < p_len) {
            return result;
        }

        vector<int> p_count(26, 0);
        vector<int> s_count(26, 0);

        // Record the frequency of characters in p
        for (char c : p) {
            p_count[c - 'a']++;
        }

        // Initialize the first window in s
        for (int i = 0; i < p_len; i++) {
            s_count[s[i] - 'a']++;
        }

        // Compare the first window
        if (p_count == s_count) {
            result.push_back(0);
        }

        // Slide the window across string s
        for (int i = p_len; i < s_len; i++) {
            // Add the new character to the current window
            s_count[s[i] - 'a']++;
            // Remove the oldest character from the window
            s_count[s[i - p_len] - 'a']--;

            // Compare frequencies
            if (p_count == s_count) {
                result.push_back(i - p_len + 1);
            }
        }

        return result;
    }
};