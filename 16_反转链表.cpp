LinkNode* reverseList(LinkNode* head){
    LinkNode h;
    h.next = NULL;
    while (head){
        LinkNode* tmp = head->next;
        head->next = h.next;
        h.next = head;
        head = tmp;
    }
    return h.next;
}
