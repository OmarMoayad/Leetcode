/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallest;

    void dfs(TreeNode* node, string current) {
        if (node == nullptr) {
            return;
        }

        char letter = 'a' + node->val;
        current = letter + current;

        
        if (node->left == nullptr && node->right == nullptr) {
            if (smallest.empty() || current < smallest) {
                smallest = current; 
            }
        }

        
        dfs(node->left, current);
        dfs(node->right, current);
    }

    string smallestFromLeaf(TreeNode* root) {
        smallest = "";          
        dfs(root, "");          
        return smallest;        
    }
};
