typedef struct _LinkNode{
    int val;
    _LinkNode * next;

}LinkNode, *LinkList;
void deleteDups(LinkList head){
    if (head == NULL || head->next == NULL) return;
    std::set<int> hash;
    hash.insert(head->val);
    LinkNode* p = head->next;
    LinkNode* rear = head;
    while (p){
        if (hash.find(p->val) == hash.end()){
            rear->next = p;
            rear = p;
            hash.insert(p->val);
            p = p->next;
        }
        else{
            // delete p
            LinkNode* q = p->next;
            delete p;
            p = q;
        }
    }
    rear->next = NULL;
}

void deleteDups2(LinkList head){
    if (head == NULL || head->next == NULL) return;
    auto removeDupsval =[](LinkList head, int val){
        LinkNode h;
        LinkNode* rear = &h;
        while (head){
            if (head->val != val){
                rear->next = head;
                rear = head;
                head = head->next;
            }
            else{
                LinkNode* q = head->next;
                delete head;
                head = q;
            }
        }
        rear->next = NULL;
        return h.next;
    };
    LinkNode h;
    LinkNode* rear = &h;
    LinkNode* p = head;
    while (p){
        rear->next = p;
        rear = p;
        p = removeDupsval(p->next, p->val);
    }
    rear->next = NULL;
}
