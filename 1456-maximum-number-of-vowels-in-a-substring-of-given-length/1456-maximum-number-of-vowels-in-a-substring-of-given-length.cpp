class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vowels = 0;
        int current_vowels = 0;
        
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                current_vowels++;
            }
        }
        max_vowels = current_vowels;

        // Slide the window through the rest of the string
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i - k])) {
                current_vowels--; // Remove the effect of the character leaving the window
            }
            if (isVowel(s[i])) {
                current_vowels++; // Add the effect of the character entering the window
            }
            
            max_vowels = max(max_vowels, current_vowels);
            
            // Early exit optimization: maximum possible vowels in length k is k
            if (max_vowels == k) {
                return k; 
            }
        }

        return max_vowels;
    }
};