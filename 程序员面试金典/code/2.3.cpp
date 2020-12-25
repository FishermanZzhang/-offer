/*EXAMPLE
 *Input: the node ‘c’ from the linked list a->b->c->d->e
 *Result: nothing is returned, but the new linked list looks like a->b->d->e
*/

typedef struct _LinkNode
{
    int val;
    _LinkNode * next;
}LinkNode, *LinkList;

bool deleteNode(LinkList head, LinkNode& node){
    if (head == NULL) return false;
    while (head->next && head->next->val != node.val){ //head->next != &node
        head = head->next;
    }
    if (head->next == NULL) return false;
    LinkNode* p = head->next;
    head->next = p->next;
    delete p;
    return true;
}

