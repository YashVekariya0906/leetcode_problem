class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                nums1[p--] = nums2[p2--];
            }
        }
        
        // If nums2 still has elements, place them at the beginning of nums1.
        // If nums1 has elements left, they are already in the correct place.
        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }
    }
};