#include <cstddef>
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode new_head, *p = head, *q;
        new_head.next = NULL;
        while (p) {
            q = p->next;
            p->next = new_head.next;
            new_head.next = p;
            p = q;
        }
        return new_head.next;
    }

    ListNode *reverseList2(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *tail = head->next;
        ListNode *new_head = reverseList2(head->next);
        head->next = tail->next;
        tail->next = head;
        return new_head;
    }
};
