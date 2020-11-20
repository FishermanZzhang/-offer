void mirrorOfTree(TreeNode* root){
	if (root == NULL) return;
	std::swap(root->left, root->right);
	mirrorOfTree(root->left), mirrorOfTree(root->right);
}
