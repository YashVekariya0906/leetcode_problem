class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,left=0,shortest=INT_MAX;

        for(int right=0; right<nums.size();right++){
            sum+=nums[right];

            while(sum>=target){
                shortest=min(shortest, right-left+1);

                sum-=nums[left];
                left++;
            }
        }
        return shortest == INT_MAX ? 0 : shortest; 
    }
};