#include <vector>
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
    std::vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        
        std::vector<double> avg_vec;
        std::deque<TreeNode *> q;
        q.push_back(root);

        while (!q.empty()) {
            int level_size = q.size();
            double level_sum = 0;

            for (int i = 0; i < level_size; i++) {
                TreeNode *node = q.front();
                q.pop_front();

                level_sum += node->val;

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            avg_vec.push_back(level_sum / level_size);
        }

        return avg_vec;
    }
};