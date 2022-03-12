//   * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    
    void traverse(TreeNode* root,vector<vector<int>>& v){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> f;
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(n == NULL){
                v.push_back(f);
                f.clear();
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
                
            }
            else{
                f.push_back(n->val);
                cout<<n->val<<" ";
                if(n->left!=NULL){
                    q.push(n->left);
                }
                if(n->right!= NULL){
                    q.push(n->right);
                }
            }
            
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL){
            return v;
        }
        traverse(root,v);
        for(int i=0;i<v.size();i++){
            if(i%2!=0){
                // v[i].reverse();
                reverse(v[i].begin(), v[i].end());
            }
        }
        return v;
    }
};