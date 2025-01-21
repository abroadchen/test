#include <cstddef>
class Solution {
public:

    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        whille (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) break;
        }
        if (q == NULL || q->next == NULL) return NULL;
        p = head;
        while (p != q) p = p->next, q = q->next;
        return p;
    }
};
