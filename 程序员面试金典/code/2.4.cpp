typedef struct _LinkNode
{
    int val;
    _LinkNode * next;
}LinkNode, *LinkList;


LinkList addList(LinkList list1, LinkList list2){
    LinkNode head;
    LinkNode* rear = &head;
    int flag = 0;
    while (list1 && list2){
        int v = list1->val + list2->val + flag;
        flag = v / 10;
        v %= 10;
        LinkNode* n = new LinkNode;
        n->val = v;
        rear->next = n;
        rear = n;
        list1 = list1->next;
        list2 = list2->next;
    }
    while (list1){
        int v = list1->val + flag;
        flag = v / 10;
        v %= 10;
        LinkNode* n = new LinkNode;
        n->val = v;
        rear->next = n;
        rear = n;
        list1 = list1->next;
    }
    while (list2){
        int v = list2->val + flag;
        flag = v / 10;
        v %= 10;
        LinkNode* n = new LinkNode;
        n->val = v;
        rear->next = n;
        rear = n;
        list2 = list2->next;
    }
    rear->next = NULL;
    return head.next;
}
