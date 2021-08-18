class Solution {
public:
    void traverse(TreeNode* root, int mx, int &res)
    {
        if(root==NULL) return;
        if(mx<=root->val) ++res;
        mx=max(mx,root->val);
        traverse(root->left,mx,res);
        traverse(root->right,mx,res);
        return;
    }
    int goodNodes(TreeNode* root) {
        //self
        int mx=INT_MIN,res=0;
        traverse(root,mx,res);
        return res;
    }
};