//
class solution37{
public:
    LinkNode* findFirstCommonNode(LinkNode* head1, LinkNode* head2){
        if (head1 == NULL || head2 == NULL) return NULL;
        int len1 = length(head1);
        int len2 = length(head2);
        LinkNode* longlink = NULL, *shortlink = NULL;
        if (len1 > len2){
            longlink = head1;
            shortlink = head2;
        }
        else{
            longlink = head2;
            shortlink = head1;
        }
        int diff = abs(len1 - len2);
        while (diff--){
            longlink = longlink->next;
        }
        while (longlink != shortlink){
            longlink = longlink->next;
            shortlink = shortlink->next;
        }
        return longlink;
    }
private:
    int length(LinkNode* head){
        int cnt = 0;
        while (head){
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
};
