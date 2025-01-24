#include <algorithm>
#include <cstddef>
using namespace std;

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        int l = head->val, r = head->val, z;
        ListNode *p = head, *h1 = nullptr, *h2 = nullptr, *q;
        while (p) l = min(p->val, l), r = max(p->val, r), p = p->next;
        if (l == r) return head;
        z = (l + r) >> 1;
        p = head;
        while (p) {
            q = p->next;
            if (p->val <= z) {
                p->next = h1;
                h1 = p;
            } else {
                p->next = h2;
                h2 = p;
            }
            p = q;
        }
        h1 = sortList(h1);
        h2 = sortList(h2);
        p = h1;
        while (p->next) p = p->next;
        p->next = h2;
        return h1;
    }
    

    int getLength(ListNode *head) {
        int n = 0;
        while (head) n += 1, head = head->next;
        return n;
    }


    ListNode *merge_sort(ListNode *head, int n) {
        if (n <= 1) return head;
        int l = n / 2, r = n - l;
        ListNode *p = head, *p1, *p2, ret;
        for (int i = 1; i < l; i++) p = p->next;
        p1 = head, p2 = p->next;
        p->next = NULL;
        p1 = merge_sort(p1, l);
        p2 = merge_sort(p2, r);
        p = &ret, ret.next = NULL;
        while (p1 || p2) {
            if (p2 == NULL || (p1 && p1->val <= p2->val)) {
                p->next = p1;
                p = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
        }
        return ret.next;
    }

    ListNode *sortList2(ListNode *head) {
        int n = getLength(head);
        return merge_sort(head, n);
    }
};
