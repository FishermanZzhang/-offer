struct ListNode{
    int data;
    ListNode* next;
};

class solution{
    public:
        void print(LinstNode* head){
            if(head == NULL) return ;
            print(head->next);
            cout << head->val << endl;
        }
}
