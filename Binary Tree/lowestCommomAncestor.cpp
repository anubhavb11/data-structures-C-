
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/

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
    
    
    bool findPath(TreeNode* root, TreeNode* p,vector<TreeNode*>& a){
        if(root == NULL){
            return false;
        }
        a.push_back(root);
        if(root == p){
            return true;
        }
        // TreeNode* ans = findPath(root->left,p,a);
        if(findPath(root->left,p,a) || findPath(root->right,p,a)){
            return true;
        }
        // ans= findPath(root->right,p,a);
        a.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        findPath(root,p,a);
        findPath(root,q,b);
        int x = min(a.size(),b.size());
        bool flag = false;
        TreeNode* ans = root;
        for(int i=0;i<x;i++){
            cout<<a[i]->val<<" ";
            if(a[i] != b[i]){
                break;
            }else{
                ans = a[i];
            }
        }
        return ans;
        
    }
};