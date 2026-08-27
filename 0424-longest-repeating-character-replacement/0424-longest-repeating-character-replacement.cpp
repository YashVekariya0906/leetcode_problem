class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Increment the count of the current character
            count[s[right] - 'A']++;
            // Update the maximum frequency of a single character in the current window
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            
            // If the number of characters we need to replace exceeds k, shrink the window
            if ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // Update the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};