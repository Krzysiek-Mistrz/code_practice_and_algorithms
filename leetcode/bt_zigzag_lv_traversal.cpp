#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if (root == nullptr) return result;

        std::queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;

        while (!q.empty()) {
            int level_size = q.size();
            std::vector<int> current_level(level_size);

            for (int i = 0; i < level_size; i++) {
                TreeNode* current_node = q.front();
                q.pop();

                int index = left_to_right ? i : (level_size - 1 - i);
                current_level[index] = current_node->val;

                if (current_node->left != nullptr) q.push(current_node->left);
                if (current_node->right != nullptr) q.push(current_node->right);
            }

            result.push_back(current_level);
            
            left_to_right = !left_to_right;
        }

        return result;
    }
};