class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findBound(nums, target, true);
        if (left == -1) {
            return {-1, -1};
        }
        int right = findBound(nums, target, false);
        return {left, right};
    }
    
private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int low = 0;
        int high = nums.size() - 1;
        int bound = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    high = mid - 1; // Continue searching to the left
                } else {
                    low = mid + 1;  // Continue searching to the right
                }
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return bound;
    }
};