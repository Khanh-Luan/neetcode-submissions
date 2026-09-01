class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> mtp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                mtp.push_back(nums[i]);
            }
        }
        for (int i = 0; i < mtp.size(); i++) {
            nums[i] = mtp[i];
        }
        return mtp.size();
    }
};