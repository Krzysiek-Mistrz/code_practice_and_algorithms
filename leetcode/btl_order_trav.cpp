#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        
        if (root == nullptr) {
            return result;
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            std::vector<int> current_level;
            
            for (int i = 0; i < level_size; i++) {
                TreeNode* current_node = q.front();
                q.pop();
                
                current_level.push_back(current_node->val);
                
                if (current_node->left != nullptr) {
                    q.push(current_node->left);
                }
                if (current_node->right != nullptr) {
                    q.push(current_node->right);
                }
            }
            
            result.push_back(current_level);
        }
        
        return result;
    }
};