void DeleteNode(ListNode** head, ListNode* pdeltenode){
	if (head == NULL || *head == NULL || pdeltenode == NULL) return;
	if ((*head)->next == NULL && (*head) == pdeltenode){
		delete pdeltenode;
		*head == NULL;
	}
	else if(pdeltenode->next != NULL){
		pdeltenode->val = pdeltenode->next->val;
		ListNode* p = pdeltenode->next;
		pdeltenode->next = p->next;
		delete p;
	}
	else{
		// 尾结点，从头遍历
	}
}
