struct BinaryTreeNode{
 int data;
 BinaryTreeNode* left;
 BinaryTreeNode* right;
 BinaryTreeNode(int val):data(val),left(NULL),right(NULL){}
};

class{
    public:
        BinaryTreeNode* construct(vector<int>& preorder, vector<int>& inorder){
            if(preorder.size() != inorder.size()){
                return NULL;
            }
            BinaryTreeNode* root = gen(preorder, 0, preorder.size() - 1, \
                                        inorder, 0 , inorder.size() - 1);
            return root;
        }
        BinaryTreeNode* gen(vector<int>& preorder, int start, int end,
                vector<int>& inorder, int left, int right){
            if(start > end || left > right) return NULL;
            BinaryTreeNode* root = new BinaryTreeNode(preorder[start]);
            auto it = std::find(inorder.begin() + left, inorder.begin() + right + 1, preorder[start]) - inorder.begin();
            root->left = gen(preorder, start + 1, it - left + start, \
                             inorder, left, it - 1);
            root->right = gen(preorder,it + 1 - right + end, end, \
                              inorder, it + 1, right);
            return root;
        }

};
