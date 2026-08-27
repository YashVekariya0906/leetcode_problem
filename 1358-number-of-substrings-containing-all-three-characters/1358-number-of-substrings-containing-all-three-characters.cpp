class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int last_seen[3] = {-1, -1, -1};
        
        for (int i = 0; i < s.length(); ++i) {
            last_seen[s[i] - 'a'] = i;
            
            int min_idx = min({last_seen[0], last_seen[1], last_seen[2]});
            
            if (min_idx != -1) {
                count += min_idx + 1;
            }
        }
        
        return count;
    }
};