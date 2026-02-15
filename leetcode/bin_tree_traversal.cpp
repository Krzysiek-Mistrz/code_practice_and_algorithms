/*
Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Logika rozwiązania
Pierwszy element z preorder to nasz aktualny węzeł.
Szukamy tego elementu w inorder.
Wszystko na lewo od niego w inorder tworzy lewe poddrzewo.
Wszystko na prawo tworzy prawe poddrzewo.
Rekurencyjnie powtarzamy proces dla obu stron.
*/

#include <unordered_map>
#include <vector>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        
        return arrayToTree(preorder, 0, inorder.size() - 1);
    }

private:
    std::unordered_map<int, int> inorder_map;
    int preorder_idx = 0;

    TreeNode* arrayToTree(std::vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);
        int pivot = inorder_map[root_val];
        root->left = arrayToTree(preorder, left, pivot - 1);
        root->right = arrayToTree(preorder, pivot + 1, right);

        return root;
    }
};