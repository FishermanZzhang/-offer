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


class solution13{
public:
	void DeleteNode(ListNode** head, ListNode* pdeltenode){
		if (head == NULL || (*head) == NULL || pdeltenode == NULL)
			return;
		if ((*head)->next == NULL && pdeltenode == *head){
			delete pdeltenode;
			*head = NULL;
		}
		else if (pdeltenode->next){
			auto q = pdeltenode->next;
			pdeltenode->val = q->val;
			pdeltenode->next = q->next;
			delete q;
		}
		else{
			auto p = *head;
			while (p->next != pdeltenode){
				p = p->next;
			}
			p->next == NULL;
			delete pdeltenode;
		}
	}
};
