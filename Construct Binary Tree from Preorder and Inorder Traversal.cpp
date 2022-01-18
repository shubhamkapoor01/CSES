class Solution {
public:
    TreeNode* solve(int ps, int pe, int is, int ie, vector<int> &preorder, 
                        vector<int> &inorder, unordered_map<int, int> &m) {
        
        if (ps > pe || is > ie) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = m[root -> val];
        int lsize = inRoot - is;
        
        root -> left = solve(ps + 1, ps + lsize, is, inRoot - 1, preorder, inorder, m);
        root -> right = solve(ps + lsize + 1, pe, inRoot + 1, ie, preorder, inorder, m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i ++) {
            m[inorder[i]] = i;
        }
        
        return solve(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder, m);
    }
};
