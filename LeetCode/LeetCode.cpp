#include "../config.h"
#include <iterator>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // std:unordered_map is an associative container that contains key-value pairs with unique keys
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            // finds element with specific key 
            auto item = hashtable.find(target - nums[i]);
            if (item != hashtable.end()) {
                return {item->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(max(nums[0], nums[1]));
        for (int i = 2; i < size; ++i) {
            dp.push_back(max(dp[i-2] + nums[i], dp[i-1]));
        }
        return dp[size-1];
    }
};

int main() {
    vector<int> msg = {114,117,207,117,235,82,90,67,143,146,53,108,2005,169,241,202,144,240};
}
