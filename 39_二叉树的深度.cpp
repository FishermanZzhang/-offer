//question 1:
class solution39_1{
    public:
        int depth(BinaryTreeNode* root){
            if (root == NULL) return 0;
            int left = depth(root->left);
            int right = depth(root->right);
            return std::max(left, right) + 1;
        }
};


//question 2
class solution39_2{
    public:
        bool isBlance(BinaryTreeNode* root){
            if (root == NULL) return true;
            int left = depth(root->left);
            int right = depth(root->right);
            return abs(left - right) <= 1 && isBlance(root->left) && isBlance(root->right);
        }
        int depth(BinaryTreeNode* root){
            if (root == NULL) return 0;
            int left = depth(root->left);
            int right = depth(root->right);
            return std::max(left, right) + 1;
        }
};

class solution39_2_2{
    public:
        bool isBlance(BinaryTreeNode* root){
            int d = 0;
            return isBlance(root, d);
        }
        bool isBlance(BinaryTreeNode* root, int& depth){
            if (root == NULL){
                depth = 0;
                return true;
            }
            int left = 0;
            int right = 0;
            if (isBlance(root->left, left) && isBlance(root->right, right)){
                depth = std::max(left, right) + 1;
                return abs(left - right) <= 1;
            }
            return false;
        }
};
