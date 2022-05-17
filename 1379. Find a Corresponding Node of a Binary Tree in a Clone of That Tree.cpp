/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void inOrder(TreeNode* cloned, TreeNode* target){
        if(cloned == nullptr) return;
        if(cloned->val == target->val){
            ans = cloned;
            return;
        }
        inOrder(cloned->left, target);
        inOrder(cloned->right, target);
        return;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inOrder(cloned, target);
        return ans;
    }
};