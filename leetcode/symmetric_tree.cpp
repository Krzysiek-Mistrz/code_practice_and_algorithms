/*
Topics
premium lock iconCompanies
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true
*/

#include <iostream>
#include <deque>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        std::deque<TreeNode *> q;
        q.push_back(root->left);
        q.push_back(root->right);

        while (!q.empty()) {
            TreeNode *right = q.back(); q.pop_back();
            TreeNode *left  = q.back(); q.pop_back();

            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;
            if (left->val != right->val) return false;

            q.push_back(left->left);
            q.push_back(right->right);
            q.push_back(left->right);
            q.push_back(right->left);
        }

        return true;
    }
};