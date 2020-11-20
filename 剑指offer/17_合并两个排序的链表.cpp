struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {
	}
};

ListNode* merge(ListNode* h1, ListNode* h2){
	ListNode head(0);
	ListNode* rear = &head;
	while (h1 && h2){
		if (h1->val > h2->val){
			rear->next = h2;
			rear = h2;
			h2 = h2->next;
		}
		else{
			rear->next = h1;
			rear = h1;
			h1 = h1->next;
		}
	}
	if (h1){
		rear->next = h1;
	}
	if (h2){
		rear->next = h2;
	}
	return head.next;
}
