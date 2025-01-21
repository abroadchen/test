#include <cstddef>
class Solution {
public:

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode new_head, *p = &new_head, *q = p;
        new_head.next = head;
        for (int i = 0; i <= n; i++) q = q->next;
        while (q) p = p->next, q = q->next;
        p->next = p->next->next;
        return new_head.next;
    }
};
