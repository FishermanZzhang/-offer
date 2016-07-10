struct BinaryTreeNode{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode() :data(0), left(NULL), right(NULL){}

};
typedef BinaryTreeNode* BinaryTree;
class solutionfindpath{
public:
    void findpath(BinaryTree root, int sum){
        findpath(root, 0, sum);
    }
    void findpath(BinaryTreeNode* pnode, int k, int sum){
        if (pnode == NULL) return;
        k += pnode->data;
        record_.push_back(pnode->data);
        if (k == sum){ // k== sum && pnode->left == NULL && pnode->right == NULL;
            for (auto i : record_){
                cout << i << " ";
            }
            cout << endl;
        }
        findpath(pnode->left, k, sum);
        findpath(pnode->right, k, sum);
        record_.pop_back();
    }
private:
    vector<int> record_;
};
