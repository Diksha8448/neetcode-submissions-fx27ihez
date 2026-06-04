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
// we will store inorder and its indexes so that we have 
//index of every number
    unordered_map<int,int>inorderMap;

// for iterating preorder
    int preIndex=0;
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int left,int right){
           if(left>right){
            return NULL;
           }

           int rootval=preorder[preIndex++];

           TreeNode* root=new TreeNode(rootval);

           int mid=inorderMap[rootval];

           root->left = build(preorder, inorder, left, mid - 1);
           root->right = build(preorder, inorder, mid + 1, right);
            
           return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]]=i;
        }
        return build(preorder, inorder, 0, inorder.size() - 1);

    }
};
