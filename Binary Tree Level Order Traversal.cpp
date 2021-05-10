class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    void traverse(TreeNode* root, vector<vector<int>> &res, int l)
    {
        if(root==NULL) return;
        res[l].push_back(root->val);
        traverse(root->left,res,l+1);
        traverse(root->right,res,l+1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        int h=height(root);
        vector<vector<int>> res(h);
        traverse(root,res,0);
        return res;
    }
};