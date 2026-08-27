class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int current_whites = 0;
        int min_recolors = k; 

        // Count the number of 'W's in the first window of size k
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W') {
                current_whites++;
            }
        }
        
        min_recolors = current_whites;

        // Slide the window across the rest of the string
        for (int i = k; i < blocks.length(); ++i) {
            // Remove the effect of the character that is left behind
            if (blocks[i - k] == 'W') {
                current_whites--;
            }
            // Add the effect of the new character entering the window
            if (blocks[i] == 'W') {
                current_whites++;
            }
            
            // Update the minimum recolors needed
            min_recolors = min(min_recolors, current_whites);
        }

        return min_recolors;
    }
};