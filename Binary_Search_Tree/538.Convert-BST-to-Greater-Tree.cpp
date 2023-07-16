class Solution {
public:
    void solve(TreeNode* root, int& sum) {
        if(root==NULL) return;

        if(root->right) solve(root->right, sum);
        sum += root->val;
        root->val = sum;
        if(root->left) solve(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return root;
    }
};
