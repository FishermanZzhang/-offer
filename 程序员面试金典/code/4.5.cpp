struct TreeNode3{
	TreeNode3* left;
	TreeNode3* right;
	TreeNode3* parent;
	int val;
	TreeNode3(int val) :val(val), left( NULL), right(NULL), parent(NULL){
	};
};
class Solution{
	public:
		TreeNode3* next( TreeNode3* node){
			if (node == NULL) return NULL;
			if (node->right){
				node = node->right;
				if (node == NULL) return NULL;
				while (node->left){
					node = node->left;
				}
				return node;
			}
			else{
				while (node->parent && node->parent->right == node){ // node->parent->left != node
					node = node->parent;
				}
				return node->parent;
			}

		}
};
