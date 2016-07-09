struct LinkNode{
    int data;
    LinkNode* next;
};
LinkNode* findKthOfTail(LinkNode* head, int k){
    if (k <= 0) return NULL;
    LinkNode h;
    h.next = head;
    LinkNode* p = &h;
    while (p && k--){
        p = p->next;
    }
    if (p == NULL){
        return NULL;
    }
    LinkNode* q = &h;
    while (p){
        p = p->next;
        q = q->next;
    }
    return q;
}
