#include <climits>

class Solution {
private:
    bool validate(TreeNode* node, long long low, long long high) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= low || node->val >= high) {
            return false;
        }

        return validate(node->left, low, node->val) && 
               validate(node->right, node->val, high);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};