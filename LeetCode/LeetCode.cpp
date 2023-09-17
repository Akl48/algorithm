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

    int rob(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start+1]);
        for (int i = start + 2; i <= end; ++i) {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }

    int rob_v2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size <= 3) {
            return *max_element(nums.begin(), nums.end());
        }
        return max(rob(nums, 0, size - 2), rob(nums, 1, size - 1));
    }

    string reverseString(const string& str) {
        string reversedStr;
        int length = str.length();

        for (int i = length - 1; i >= 0; --i) {
            reversedStr += str[i];
        }   

        return reversedStr;
    }

    bool isPalindrome(int x) {
        if (x < 0) return false;

        string str = s.to_string();
        string newStr = reverseString(str);
        if (str == newStr) {
            return true;
        }
        return false;
    }
};

int main() {

}
