class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Sort the input array
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Loop through the array
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates for the current element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Two-pointer approach
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Move the pointers to skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left; // Need a larger number, move left pointer forward
                } else {
                    --right; // Need a smaller number, move right pointer backward
                }
            }
        }

        return result;
    }
};
