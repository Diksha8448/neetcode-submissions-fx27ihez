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
   bool isSame(TreeNode* p,
                TreeNode* q) {

        // both null
        if (!p && !q) {
            return true;
        }

        // one null or values differ
        if (!p || !q ||
            p->val != q->val) {

            return false;
        }

        return isSame(p->left, q->left) &&
               isSame(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        // subtree found
        if (isSame(root, subRoot)) {
            return true;
        }

        // search left or right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
