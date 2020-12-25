class Solution{
	public:
		TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
			{
				// m1
				//if (root == NULL) return NULL;
				//if (connect(root->left, p) && connect(root->left, q)){
				//	return commonAncestor(root->left, p, q);
				//}
				//if (connect(root->right, p) && connect(root->right, q)){

				//	return commonAncestor(root->right, p, q);
				//}
				//return root;
			}
			if (root == NULL) return NULL;
			vector<TreeNode*> path1;
			vector<TreeNode*> path2;
			node2root(root, p, path1);
			node2root(root, q, path2);
			int len = std::min(path1.size() - 1, path2.size() - 1);
			for (int i = len; i >= 0; --i){
				if (path1[i] == path2[i])
					return path1[i];
			}
			return NULL;
		}
	private:
		bool node2root(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
			if (root == NULL) return false;
			path.push_back(root);
			if (root == node)  return true;
			bool found = node2root(root->left, node, path);
			if (!found) node2root(root->right, node, path);
			if (!found) path.pop_back();
		}
		bool connect(TreeNode* s, TreeNode* e){
			if (s == NULL) return false;
			if (s == e) return true;
			return connect(s->left, e) || connect(s->right, e);
		}
};
