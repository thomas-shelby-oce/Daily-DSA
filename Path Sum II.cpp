class Solution {
public:
    int curr;
    vector<int> v;
    vector<vector<int>> res;
    void traverse(TreeNode* root, int curr, int &targetSum)
    {
        if(root==NULL) return;
        curr+=root->val;
        v.push_back(root->val);
        if(!root->left&&!root->right)
        {
            if(curr==targetSum) res.push_back(v);
            v.pop_back();
            curr-=root->val;
            return;
        }
        traverse(root->left,curr,targetSum);
        traverse(root->right,curr,targetSum);
        v.pop_back();
        curr-=root->val;
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //self
        curr=0;
        traverse(root,curr,targetSum);
        return res;
    }
};