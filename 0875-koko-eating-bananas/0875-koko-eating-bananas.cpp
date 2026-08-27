class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        // The maximum possible eating speed we would ever need is the size of the largest pile
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hours_needed = 0;
            
            for (int pile : piles) {
                // Calculate ceiling division without floating-point math or integer overflow
                hours_needed += pile / mid + (pile % mid != 0);
            }
            
            // If Koko can finish all bananas at this speed, try a slower speed (left half)
            if (hours_needed <= h) {
                right = mid;
            } 
            // If she takes too long, she must eat faster (right half)
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};