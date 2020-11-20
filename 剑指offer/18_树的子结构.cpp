bool hasSubTree(TreeNode* root, TreeNode* subroot){
	function<bool(TreeNode*, TreeNode*)> same = [&same](TreeNode* root, TreeNode* subroot){
		if (subroot == NULL) return true;
		if (root == NULL) return false;
		return root->val == subroot->val && \
		   	  same(root->left, subroot->left) && \
			  same(root->right, subroot->right);
	};
	if (subroot == NULL) return true;
	if (root == NULL) return false;
	bool flag = false;
	if (root->val == subroot->val){
		flag = same(root, subroot);
	}
	if (!flag){
		flag = hasSubTree(root->left, subroot) || hasSubTree(root->right, subroot);
	}
	return flag;
}
