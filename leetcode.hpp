#pragma once
#include <bits/stdc++.h>

#ifdef LOCAL
// Full definitions for local testing
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#endif

class LC {  // Short for LeetCode
   public:
    // Parse 1D integer array: [-1,0,1,2,-1,-4]
    inline static std::vector<int> arr(const std::string& s) {
        std::vector<int> res;
        int num = 0, sign = 1;
        bool in_num = false;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                in_num = true;
            } else if (c == '-') {
                sign = -1;
            } else {
                if (in_num) {
                    res.push_back(sign * num);
                    num = 0;
                    sign = 1;
                    in_num = false;
                }
            }
        }
        if (in_num) res.push_back(sign * num);
        return res;
    }

    // Parse 2D integer array: [[1,2,3],[4,5,6],[7,8,9]]
    inline static std::vector<std::vector<int>> arr2d(const std::string& s) {
        std::vector<std::vector<int>> res;
        std::string current;
        int depth = 0;
        for (char c : s) {
            if (c == '[') {
                depth++;
                if (depth == 2) current = "[";
            } else if (c == ']') {
                if (depth == 2) {
                    current += "]";
                    res.push_back(arr(current));
                }
                depth--;
            } else if (depth == 2) {
                current += c;
            }
        }
        return res;
    }

    // Parse single string: "hello"
    inline static std::string str(const std::string& s) {
        std::string res;
        bool in_quotes = false;
        for (char c : s) {
            if (c == '"') {
                in_quotes = !in_quotes;
            } else if (in_quotes) {
                if (c == '\\') {
                    // Handle escape sequences if needed
                }
                res += c;
            }
        }
        return res;
    }

    // Parse two strings: "ab" "eidbaooo"
    inline static std::pair<std::string, std::string> str_str(const std::string& s) {
        std::string s1, s2;
        bool in_quotes = false;
        bool first_done = false;
        std::string* current = &s1;

        for (char c : s) {
            if (c == '"') {
                if (in_quotes && !first_done) {
                    first_done = true;
                    current = &s2;
                }
                in_quotes = !in_quotes;
            } else if (in_quotes) {
                *current += c;
            }
        }

        return {s1, s2};
    }

    // Parse array of strings: ["eat","tea","tan","ate","nat","bat"]
    inline static std::vector<std::string> strarr(const std::string& s) {
        std::vector<std::string> res;
        std::string current;
        bool in_quotes = false;
        for (char c : s) {
            if (c == '"') {
                if (in_quotes) {
                    res.push_back(current);
                    current.clear();
                }
                in_quotes = !in_quotes;
            } else if (in_quotes) {
                current += c;
            }
        }
        return res;
    }

    // Parse 2D character array: [["1","1","1"],["1","0","1"],["1","1","1"]]
    inline static std::vector<std::vector<char>> chararr2d(const std::string& s) {
        std::vector<std::vector<char>> res;
        std::vector<char> current_row;
        bool in_quotes = false;
        int depth = 0;

        for (char c : s) {
            if (c == '[') {
                depth++;
                if (depth == 2) current_row.clear();
            } else if (c == ']') {
                if (depth == 2 && !current_row.empty()) {
                    res.push_back(current_row);
                }
                depth--;
            } else if (c == '"') {
                in_quotes = !in_quotes;
            } else if (in_quotes && depth == 2) {
                current_row.push_back(c);
            }
        }
        return res;
    }

    // Parse linked list: [1,2,3,4,5]
    // Note: You'll need to define ListNode first
    inline static ListNode* list(const std::string& s) {
        auto vals = arr(s);
        if (vals.empty()) return nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int val : vals) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        return dummy->next;
    }

    // Parse tree (level-order with nulls): [1,2,3,null,null,4,5]
    // Note: You'll need to define TreeNode first
    inline static TreeNode* tree(const std::string& s) {
        std::vector<std::string> tokens;
        std::string token;
        bool in_word = false;

        for (char c : s) {
            if (isalnum(c) || c == '-') {
                token += c;
                in_word = true;
            } else if (in_word) {
                tokens.push_back(token);
                token.clear();
                in_word = false;
            }
        }
        if (in_word) tokens.push_back(token);

        if (tokens.empty() || tokens[0] == "null") return nullptr;

        TreeNode* root = new TreeNode(std::stoi(tokens[0]));
        std::queue<TreeNode*> q;
        q.push(root);

        for (size_t i = 1; i < tokens.size(); i++) {
            TreeNode* curr = q.front();

            // Left child
            if (tokens[i] != "null") {
                curr->left = new TreeNode(std::stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;

            // Right child
            if (i < tokens.size() && tokens[i] != "null") {
                curr->right = new TreeNode(std::stoi(tokens[i]));
                q.push(curr->right);
            }

            q.pop();
        }

        return root;
    }

    // Parse graph as adjacency list: [[1,2],[0,2],[0,1]]
    inline static std::vector<std::vector<int>> graph(const std::string& s) {
        return arr2d(s);  // Same format as 2D array
    }

    // Parse array of pairs/tuples: [[1,2],[3,4],[5,6]]
    inline static std::vector<std::pair<int, int>> pairs(const std::string& s) {
        auto matrix = arr2d(s);
        std::vector<std::pair<int, int>> res;
        for (const auto& row : matrix) {
            if (row.size() >= 2) {
                res.push_back({row[0], row[1]});
            }
        }
        return res;
    }
};
