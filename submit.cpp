#include "helper.hpp"
#include <bits/stdc++.h>
#include <cctype>
#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

class Solution {
public:
    bool isPalindrome(string s) {
        //given a string determine if its a palindrome or not 
        //using 2 ptr
        int left{0}; int right = (int)s.size();
        if (right == 0) return true;
        right--;


        while (left < right)  {
            while (left < right&& !isalnum( static_cast<unsigned char>(s[left]))) {
                left +=1;
            }
            while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) {
                right -=1;
            }
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++, right--;

        }
        return true;
    }
};

#ifdef LOCAL
static void solve() {
  int n;
  cin >> n;
  cin.ignore(100, '\n');
  vector<string> lines(n);
  for (int i{}; i< n; ++i) {
    getline(cin,lines[i]);
    }
    cout << lines[0];
    auto ans = Solution().isPalindrome(lines[0]);

    cout << (ans ? "true" : "false");

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
#endif
