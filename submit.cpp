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

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //an anagram of a word has the same count as a word we can view this as permutation similar to last problem
        //our check will occur if window is p size and p count matches with letters 
        
    }
};

#ifdef LOCAL
static void solve() {
    std::string line;
    getline(std::cin, line);
    // cout << "this is line" << line << " ";
    // int k;

    // cin >> k;
    // cin.ignore();
    // cout << "this is k " << k << " ";
    //
    // Pick based on problem:
    // auto nums = LC::arr(line);  // [1,2,3]
    // auto matrix = LC::arr2d(line);             // [[1,2],[3,4]]
    // auto s = LC::str(line);  // "hello"
    auto [s1, s2] = LC::str_str(line);  // 2 strings
    // auto words = LC::strarr(line);             // ["abc","def"]
    // auto grid = LC::chararr2d(line);           // [["1","0"],["0","1"]]
    // auto head = LC::list(line);                // [1,2,3,4,5]
    // auto root = LC::tree(line);                // [1,2,3,null,null,4,5]
    // auto adj = LC::graph(line);                // [[1,2],[0,2]]
    // auto points = LC::pairs(line);             // [[1,2],[3,4]]
    std::cout << "[";
    auto ans = Solution().findAnagrams(s1, s2);

    cout << ans << " ";
    std::cout << "]\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    // cout << "hello weorld";
    while (t--) solve();
    return 0;
}
#endif
