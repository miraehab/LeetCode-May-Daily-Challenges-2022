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
    //level, val of the node
    vector<pair<int, int>> leaves;
    //int cnt = 0;
public:
    void DFS(TreeNode* root, int cnt){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            leaves.push_back({cnt, root->val});
        }
        DFS(root->left, cnt + 1);
        DFS(root->right, cnt + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        DFS(root, 0);
        int ans = 0, maxi = -100;
        sort(leaves.begin(), leaves.end());
        for(int i = leaves.size()-1; i >= 0; --i){
            if(i == leaves.size()-1) maxi = leaves[i].first;
            if(leaves[i].first == maxi){
                ans+=leaves[i].second;
            }else{
                break;
            }
        }
        /* for(pair<int, int> i : leaves){
            cout<<i.first<<" "<<i.second<<endl;
        } */
        return ans;
    }
};