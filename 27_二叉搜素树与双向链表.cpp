// any binary tree to D-linklist
class solutionconvert{
    public:
        BinaryTreeNode* convertTree2DoubleLinkList(BinaryTreeNode* root){
            pair<BinaryTreeNode*, BinaryTreeNode*> headtail = convert(root);
            return headtail.first;
        }
        pair<BinaryTreeNode*, BinaryTreeNode*> convert(BinaryTreeNode* root){
            if (root == NULL) return make_pair(nullptr, nullptr);
            pair<BinaryTreeNode*, BinaryTreeNode*> htleft = convert(root->left);
            pair<BinaryTreeNode*, BinaryTreeNode*> htright = convert(root->right);
            if (htleft.second == NULL){
                if (htright.first == NULL){
                    return make_pair(root, root);
                }
                root->left = htright.first;
                htright.first->right = root;
                return make_pair(root, htright.second);
            }
            else{
                htleft.second->left = root;
                root->right = htleft.second;
                if (htright.first == NULL){
                    return make_pair(htleft.first, root);
                }
                root->left = htright.first;
                htright.first->right = root;
                return make_pair(htleft.first, htright.second);
            }
        }
};
