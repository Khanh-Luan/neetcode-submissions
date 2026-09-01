class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                sum += 1;
                max_count = max(sum, max_count);
            }
            else sum = 0;
        }
        return max_count;
    }
};