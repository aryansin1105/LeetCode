class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root),q.push(root);
        TreeNode* l = NULL,*r = NULL;
        while(!q.empty()){
            l = q.front();q.pop();
            r = q.front();q.pop();

            if(l->val != r->val) return false;
            if(l->left && r->right){
                q.push(l->left);
                q.push(r->right);
            }else if(l->left || r->right) return false;
            if(l->right && r->left){
                q.push(l->right);
                q.push(r->left);
            }else if(l->right || r->left) return false;
        }
        return true;
    }
};

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
    bool func(TreeNode *l, TreeNode *r){
        //If both the nodes are NULL --> Symmetric 
        if(!l && !r) return true ;

        //If one is NULL but other is not --> Non-symmetric
        if(!l || !r) return false ;

        //If both exists but their values are not same --> Not Symmetric
        if(l->val != r->val) return false ;

        //It both the nodes exists and their values are also equal --> Can be symmetric
        //Hence, check for the sub-trees below them.
        return func(l->left, r->right) && func(l->right, r->left) ;
    }

    bool isSymmetric(TreeNode* root) {

        //func() is used to determine symmetric or non-symmetric        
        return func(root->left, root->right) ;
    }
};