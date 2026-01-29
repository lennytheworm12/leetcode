#include <bits/stdc++.h>
#ifdef LOCAL
#include "helper.hpp"
#include "leetcode.hpp"
#if __has_include("debug.h")
#include "debug.h"
#endif
#endif

#ifndef debug
#define debug(...)  // Fallback if debug wasn't defined
#endif
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
/*
Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2], such that they
add up to a given target number target and index1 < index2. Note that index1 and
index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.

*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // given an array of integers return the triplets such that t1+t2+t3 = 0
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i{}; i < nums.size(); ++i) {
            //(nums[j] + nums[k]) = - nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            // for each double relating to i
            while (l < r) {
                // l and r shouldnt touch here because we dont want to include duplicate elements
                int sum = nums[l] + nums[r] + nums[i];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    printf("l is %d and r is %d\n", l, r);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return ans;
    }
};

#ifdef LOCAL
static void solve() {
    std::string line;
    getline(std::cin, line);

    // Pick based on problem:
    auto nums = LC::arr(line);  // [1,2,3]
    // auto matrix = LC::arr2d(line);             // [[1,2],[3,4]]
    // auto s = LC::str(line);                    // "hello"
    // auto words = LC::strarr(line);             // ["abc","def"]
    // auto grid = LC::chararr2d(line);           // [["1","0"],["0","1"]]
    // auto head = LC::list(line);                // [1,2,3,4,5]
    // auto root = LC::tree(line);                // [1,2,3,null,null,4,5]
    // auto adj = LC::graph(line);                // [[1,2],[0,2]]
    // auto points = LC::pairs(line);             // [[1,2],[3,4]]
    std::cout << "[";
    auto ans = Solution().threeSum(nums);

    cout << ans << " ";
    std::cout << "]\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // cout << "hello weorld";
    while (t--) solve();
    return 0;
}
#endif
