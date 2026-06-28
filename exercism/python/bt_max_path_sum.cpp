#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int max_sum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr) return 0;

        int left_gain = max(maxGain(node->left), 0);
        int right_gain = max(maxGain(node->right), 0);
        int current_path_sum = node->val + left_gain + right_gain;
        max_sum = max(max_sum, current_path_sum);

        return node->val + max(left_gain, right_gain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return max_sum;
    }
};